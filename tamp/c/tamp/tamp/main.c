//
//  main.c
//  tamp
//
//  Created by 吴洋 on 14-3-15.
//  Copyright (c) 2014年 吴洋. All rights reserved.
//

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
//#include <stdatomic.h>
#include <sys/time.h>
#include <string.h>

#define NUM_THREADS 2
#define LOOP_NUM 10000000


pthread_key_t thread_id_key;

int counter;
pthread_mutex_t thread_id_mutex;
void init_thread_id(){
    pthread_mutex_init(&thread_id_mutex, NULL);
    pthread_key_create(&thread_id_key, NULL);
    counter = 0;
}

int get_thread_id(){
    int* id = (int*)pthread_getspecific(thread_id_key);
    if(id == NULL){
        id = (int*)malloc(sizeof(int));
        pthread_mutex_lock(&thread_id_mutex);
        *id = counter++;
        pthread_setspecific(thread_id_key, id);
        pthread_mutex_unlock(&thread_id_mutex);
    }
    return *id;
}

void* hello(void* arg){
    printf("Hello from thread %i\n", get_thread_id());
    return NULL;
}

bool peterson_flag[2];
int peterson_victim;
void peterson_lock(){
    int i = get_thread_id();
    int j = i - 1;
    peterson_flag[i] = true;
    peterson_victim = i;
    while(peterson_flag[j] && peterson_victim == i){};
}
void peterson_unlock(){
    int i = get_thread_id();
    peterson_flag[i] = false;
}

int tas_state = 0;

void tas_lock(){
    while (__sync_lock_test_and_set(&tas_state, 1) ){}
}
void tas_unlock(){
    __sync_lock_release(&tas_state);
}
int ttas_state = 0;

void ttas_lock(){
    while (true) {
        while(ttas_state){};
        if(!__sync_lock_test_and_set(&ttas_state, 1))
            return;
    }
}
void ttas_unlock(){
    __sync_lock_release(&ttas_state);
}

int backoff_lock_min_delay, backoff_lock_max_delay;
int backoff_lock_limit;
int backoff_state = 0;
void backoff_lock_init(){
    backoff_lock_min_delay = 1;
    backoff_lock_max_delay = 100;
    backoff_lock_limit = backoff_lock_min_delay;
}
void backoff_lock(){
    while (true) {
        while(backoff_state){};
        if(!__sync_lock_test_and_set(&backoff_state, 1))
            return;
        else {
            int delay = rand() % backoff_lock_limit;
            backoff_lock_limit *= 2;
            if(backoff_lock_limit > backoff_lock_max_delay){
                backoff_lock_limit = backoff_lock_max_delay;
            }
            usleep(delay);
        }
    }
}

void backoff_unlock(){
    __sync_lock_release(&backoff_state);
}


int alock_size;
int alock_tail = 0;
int* alock_flag = 0;
pthread_key_t alock_slot;
int alock_cacheline_ratio = 32;
void alock_init(int thread_num){
    alock_size = thread_num;
    alock_flag = malloc(sizeof(int)*thread_num*alock_cacheline_ratio);
    memset(alock_flag, 0, sizeof(int)*thread_num*alock_cacheline_ratio);
    alock_flag[0] = 1;
    pthread_key_create(&alock_slot, NULL);
}

void alock_lock(){
    int slot = __sync_fetch_and_add(&alock_tail, 1) % alock_size;
    int* p_slot = (int*)pthread_getspecific(alock_slot);
    *p_slot = slot;
    pthread_setspecific(alock_slot, p_slot);
    while(! alock_flag[alock_cacheline_ratio*slot]){
        //printf("thread %d slot %d tail %d\n", (unsigned int) pthread_self(), slot, alock_tail);
    }
}

void alock_unlock(){
    int* p_slot = (int*)pthread_getspecific(alock_slot);
    int slot = *p_slot;
    alock_flag[alock_cacheline_ratio*slot] = 0;
    alock_flag[alock_cacheline_ratio*(slot + 1) % (alock_cacheline_ratio*alock_size)] = 1;
}

pthread_mutex_t mutex;
//pthread_spinlock_t spinlock;

typedef struct _qnode{
    int locked;
} qnode;

pthread_key_t clh_lock_node_key;
pthread_key_t clh_lock_pred_key;
qnode* clh_lock_tail;
void clh_lock_init(){
    pthread_key_create(&clh_lock_node_key, NULL);
    pthread_key_create(&clh_lock_pred_key, NULL);
    clh_lock_tail = malloc(sizeof(qnode));
    clh_lock_tail->locked = 0;
}
void clh_lock_lock(){
    qnode* node = (qnode*)pthread_getspecific(clh_lock_node_key);
    node->locked = 1;
    //qnode* pred = (qnode*)__sync_lock_test_and_set((qnode*)clh_lock_tail, node);
    //pthread_setspecific(clh_lock_pred_key, pred);
    //while(pred->locked){};
}
void clh_lock_unlock(){
    qnode* node = (qnode*)pthread_getspecific(clh_lock_node_key);
    node->locked = 0;
    qnode* pred = (qnode*)pthread_getspecific(clh_lock_pred_key);
    pthread_setspecific(clh_lock_node_key, pred);
}


int counter_value = 0;

int get_and_increment1(){
    int temp = counter_value;
    counter_value = temp + 1;
    return temp;
}

int get_and_increment2(){
    peterson_lock();
    int temp = counter_value;
    counter_value = temp + 1;
    peterson_unlock();
    return temp;
}
int get_and_increment3(){
    tas_lock();
    int temp = counter_value;
    counter_value = temp + 1;
    tas_unlock();
    return temp;
}
int get_and_increment4(){
    ttas_lock();
    int temp = counter_value;
    counter_value = temp + 1;
    ttas_unlock();
    return temp;
}
int get_and_increment5(){
    backoff_lock();
    int temp = counter_value;
    counter_value = temp + 1;
    backoff_unlock();
    return temp;
}
int get_and_increment6(){
    alock_lock();
    int temp = counter_value;
    counter_value = temp + 1;
    alock_unlock();
    return temp;
}
int get_and_increment7(){
    pthread_mutex_lock(&mutex);
    int temp = counter_value;
    counter_value = temp + 1;
    pthread_mutex_unlock(&mutex);
    return temp;
}

unsigned long long int rdtscp(void)
{
    unsigned a, d;
    
    __asm__ volatile("rdtscp" : "=a" (a), "=d" (d));
    
    return ((unsigned long long)a) | (((unsigned long long)d) << 32);;
}
long long get_time_stamp(){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec*1000000LL + tv.tv_usec;
}

void* run_counter(void * arg){
    int* p_alock_slot = malloc(sizeof(int));
    *p_alock_slot = 0;
    pthread_setspecific(alock_slot, p_alock_slot);
    qnode* p_clh_lock_node = malloc(sizeof(qnode));
    pthread_setspecific(clh_lock_node_key, p_clh_lock_node);
    qnode* p_clh_lock_pred = NULL;
    pthread_setspecific(clh_lock_node_key, p_clh_lock_pred);

    struct timeval tv_begin,tv_end;
    unsigned long long tsc_begin, tsc_end;
    gettimeofday(&tv_begin, NULL);
    tsc_begin = rdtscp();
    
    
    for(int i = 0; i < LOOP_NUM; i++){
        //get_and_increment1();
        //get_and_increment2();
        //get_and_increment3();
        //get_and_increment4();
        //get_and_increment5();
        get_and_increment6();
        //get_and_increment7();
    }
    tsc_end = rdtscp();
    gettimeofday(&tv_end, NULL);
    
    //printf("s=%lu, u=%d\n", tv_end.tv_sec - tv_begin.tv_sec, tv_end.tv_usec - tv_begin.tv_usec);
     long long int tv_interval = (tv_end.tv_sec - tv_begin.tv_sec)*1000000 + (tv_end.tv_usec - tv_begin.tv_usec);
     long long int tsc_interval = tsc_end - tsc_begin;
    printf("thread %d used %lld cycles, %lld us\n", get_thread_id(), tsc_interval, tv_interval);
    free(p_alock_slot);
    free(p_clh_lock_node);
    free(p_clh_lock_pred);
    return NULL;
}


int get_processor_num(){
    int processor_num = 0;
    processor_num = (int)sysconf(_SC_NPROCESSORS_ONLN);
    if(processor_num == -1){
        perror("sysconf error");
        exit(EXIT_FAILURE);
    }
    return processor_num;
}

pthread_t* create_threads(int thread_num){
    pthread_t* threads;
    threads = malloc(sizeof(pthread_t)*thread_num);
    if(threads == NULL){
        perror("malloc error");
        exit(EXIT_FAILURE);
    }

    printf("start %d threads\n", thread_num);
    
    for(int i = 0; i < thread_num; i++){
        if(pthread_create(&threads[i], NULL, run_counter, NULL) != 0){
            perror("pthread_create error");
            exit(EXIT_FAILURE);
        }
    }
    
    return threads;
}

void main_init(int thread_num){
    init_thread_id();
    backoff_lock_init();
    alock_init(thread_num);
    pthread_mutex_init(&mutex, NULL);
}
int main(int argc, const char * argv[])
{
    int thread_num = NUM_THREADS;
    //printf("sizeof%d\n", sizeof(int));
    //int thread_num = get_processor_num();
    main_init(thread_num);
    pthread_t* threads = create_threads(thread_num);
    
    for(int i = 0; i < thread_num; i++){
        pthread_join(threads[i], NULL);
    }
    free(threads);
    printf("expected value is :%d\nthe result is: %d\n", LOOP_NUM*thread_num, counter_value);
    return 0;
}

