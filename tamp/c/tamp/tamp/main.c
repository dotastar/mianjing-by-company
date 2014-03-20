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

#define NUM_THREADS 8
#define LOOP_NUM 10000000

pthread_key_t key;
int counter;
pthread_mutex_t mutex;
void init_thread_id(){
    pthread_mutex_init(&mutex, NULL);
    pthread_key_create(&key, NULL);
    counter = 0;
}

int get_thread_id(){
    int* id = (int*)pthread_getspecific(key);
    if(id == NULL){
        id = (int*)malloc(sizeof(int));
        pthread_mutex_lock(&mutex);
        *id = counter++;
        pthread_setspecific(key, id);
        pthread_mutex_unlock(&mutex);
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

unsigned long long int rdtscp(void)
{
    unsigned a, d;
    
    __asm__ volatile("rdtscp" : "=a" (a), "=d" (d));
    
    return ((unsigned long long)a) | (((unsigned long long)d) << 32);;
}

void* run_counter(void * arg){
    struct timeval tv_begin,tv_end;
    unsigned long long tsc_begin, tsc_end;
    gettimeofday(&tv_begin, NULL);
    tsc_begin = rdtscp();
    
    
    for(int i = 0; i < LOOP_NUM; i++){
        //get_and_increment1();
        //get_and_increment2();
        //get_and_increment3();
        get_and_increment4();
    }
    tsc_end = rdtscp();
    gettimeofday(&tv_end, NULL);
    
    unsigned long long int tv_interval = (tv_end.tv_sec - tv_begin.tv_sec)*1000000 + (tv_end.tv_usec - tv_begin.tv_usec);
    unsigned long long int tsc_interval = tsc_end - tsc_begin;
    printf("thread %d used %llu cycles, %llu us\n", get_thread_id(), tv_interval, tsc_interval);
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

int main(int argc, const char * argv[])
{
    int thread_num = NUM_THREADS;
    //int thread_num = get_processor_num();
    init_thread_id();
    pthread_t* threads = create_threads(thread_num);
    
    for(int i = 0; i < thread_num; i++){
        pthread_join(threads[i], NULL);
    }
    free(threads);
    printf("expected value is :%d\nthe result is: %d\n", LOOP_NUM*thread_num, counter_value);
    return 0;
}

