#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

const int POOL_SIZE = 5;

typedef struct _job{
  void (*function)(void *);
  void *parameter;
  struct _job *prev;
  struct _job *next;
} job;

typedef struct _threadpool{
  int size;
  pthread_t *threads;
  int destroyed;
  pthread_mutex_t mutex;
  pthread_cond_t cond;
  job *head;
  job *tail;
} threadpool;

void *threadpool_loop(void *argument)
{
  threadpool *tp = (threadpool*)argument;
  while(1){
    //get job from queue
    pthread_mutex_lock(&tp->mutex);
      while(tp->head == NULL && !tp->destroyed){
      pthread_cond_wait(&tp->cond, &tp->mutex);
    }
    if(tp->destroyed){
      pthread_mutex_unlock(&tp->mutex);
      break;
    }

    job *j = tp->head;
    tp->head = j->next;
    if(tp->head == NULL) tp->tail = NULL;
    pthread_mutex_unlock(&tp->mutex);
    
    //run job
    (j->function)(j->parameter);

    free(j);
  }
  printf("%s: exit\n", __FUNCTION__);

  return NULL;
}

void threadpool_init(threadpool *tp, int pool_size){
  tp->threads = (pthread_t *)malloc(pool_size * sizeof(pthread_t));

  tp->size = pool_size;
  tp->destroyed = 0;
  pthread_mutex_init(&tp->mutex, NULL);
  pthread_cond_init(&tp->cond, NULL);
  tp->head = NULL;
  tp->tail = NULL;
  int i;
  for(i = 0; i < pool_size; ++i){
    printf("%s: creating thread %d\n", __FUNCTION__,  i);
    pthread_create(&tp->threads[i], NULL, threadpool_loop, tp);
  }

}

void threadpool_addjob(threadpool *tp, void *function, void *parameter){
  job *j = (job *)malloc(sizeof(job));
  j->function = function;
  j->parameter = parameter;
  j->prev = NULL;
  j->next = NULL;
  printf("%s: for %d\n", __FUNCTION__, *(int *) parameter);
  // add job to q
  pthread_mutex_lock(&tp->mutex);
  if(tp->tail == NULL){
    tp->head = j;
    tp->tail = j;
  } else {
    j->prev = tp->tail;
    tp->tail->next = j;
    tp->tail = j;
  }
  pthread_mutex_unlock(&tp->mutex);
  //printf("broadcast for %d\n", *(int *) parameter);
  //pthread_cond_broadcast(&tp->cond);
  pthread_cond_signal(&tp->cond);
}


void threadpool_destroy(threadpool *tp){
  printf("enter %s\n", __FUNCTION__);
  if(tp->destroyed == 1) return;
  else tp->destroyed = 1;
  pthread_mutex_lock(&tp->mutex);
    job *p = tp->head;
  while(p != NULL){
    printf("free a job\n");
    job *t = p;
    p = p->next;
    free(t);
    t = NULL;
  }
  pthread_mutex_unlock(&tp->mutex);
  pthread_cond_broadcast(&tp->cond);
  int i;
  for(i = 0; i < tp->size; ++i){
    printf("%s: %d\n", __FUNCTION__, i);
    pthread_join(tp->threads[i], NULL);
  }
  pthread_mutex_destroy(&tp->mutex);
  pthread_cond_destroy(&tp->cond);
  free(tp->threads);
  free(tp);
}

void task(void *p){
  printf("thread %u, running task %d\n", pthread_self(), *(int *)p);
}

int main() {
  threadpool *tp = malloc(sizeof(threadpool));
  threadpool_init(tp, POOL_SIZE);
  int i;
  int a[3*POOL_SIZE];
  for(i = 0; i < 3*POOL_SIZE;++i){
    a[i] = i;
    threadpool_addjob(tp, &task, &a[i]);
  }
  threadpool_destroy(tp);
  return 0;
}
