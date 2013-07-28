#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

/* const int POOL_SIZE = 5; */
/* const int PROCUTION_RANGE = 100; */
#define POOL_SIZE 5
#define PROCUTION_RANGE 100
#define PRODUCER_NUM 10
#define CONSUMER_NUM 6

int pool[POOL_SIZE];
int begin;
int end;
int count = 0;
pthread_mutex_t pool_mutex;
pthread_cond_t not_full_cond;
pthread_cond_t not_empty_cond;

void *producer(void *t) {
  int tid = (long)t;
  while(1){
    int sleep_time = rand()%10;
    printf("producer %d will sleep %d seconds\n", tid, sleep_time);
    sleep(sleep_time);
    
    pthread_mutex_lock(&pool_mutex);
    while(count == POOL_SIZE) pthread_cond_wait(&not_full_cond, &pool_mutex);
    int new_production = rand()%100;
    printf("producer %d put %d in pool, (begin=%d, end=%d, count=%d)\n", tid, new_production, begin, end, count);
    pool[end] = new_production;
    end = (end+1)%POOL_SIZE;
    ++count;
    pthread_cond_broadcast(&not_empty_cond);
    pthread_mutex_unlock(&pool_mutex);
  }
  pthread_exit(NULL);
}
void *consumer(void *t) {
  int tid = (long)t;
  while(1){
    int sleep_time = rand()%10;
    printf("consumer %d will sleep %d seconds\n", tid, sleep_time);
    sleep(sleep_time);

    pthread_mutex_lock(&pool_mutex);
    while(count == 0) pthread_cond_wait(&not_empty_cond, &pool_mutex);
    printf("consumer %d get %d in pool, (begin=%d, end=%d, count=%d)\n", tid, pool[begin], begin, end, count);
    begin = (begin+1)%POOL_SIZE;
    --count;
    pthread_cond_broadcast(&not_full_cond);
    pthread_mutex_unlock(&pool_mutex);
  }
  pthread_exit(NULL);
}

int main() {
  pthread_t producer_threads[PRODUCER_NUM];
  pthread_t consumer_threads[CONSUMER_NUM];
  pthread_attr_t  attr;
  
  pthread_mutex_init(&pool_mutex, NULL);
  pthread_cond_init(&not_full_cond, NULL);
  pthread_cond_init(&not_empty_cond, NULL);
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

  begin = 0; end = 0; count = 0;
  int i;
  for(i = 0; i < PRODUCER_NUM; ++i) {
    pthread_create(&producer_threads[i], NULL, producer,(void *)i);
  }
  for(i = 0; i < CONSUMER_NUM; ++i) {
    pthread_create(&consumer_threads[i], NULL, consumer,(void *)i);
  }
  
  for(i = 0; i < PRODUCER_NUM; ++i) {
    pthread_join(producer_threads[i], NULL);
  }
  for(i = 0; i < CONSUMER_NUM; ++i) {
    pthread_join(consumer_threads[i], NULL);
  }

  pthread_attr_destroy(&attr);
  pthread_cond_destroy(&not_empty_cond);
  pthread_cond_destroy(&not_full_cond);
  pthread_mutex_destroy(&pool_mutex);
  pthread_exit(NULL);
}
