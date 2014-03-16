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

#define NUM_THREADS 8

pthread_key_t key;
int counter;
pthread_mutex_t mutex;
void threadID_init(){
    pthread_mutex_init(&mutex, NULL);
    pthread_key_create(&key, NULL);
    counter = 0;
}

int threadID_get(){
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
    printf("Hello from thread %i\n", threadID_get());
    return NULL;
}

int main(int argc, const char * argv[])
{
    pthread_t thread[NUM_THREADS];
    
    threadID_init();
    int i;
    for(i = 0; i < NUM_THREADS; i++){
        if(pthread_create(&thread[i], NULL, hello, NULL) != 0){
            printf("pthread_create() error\n");
            exit(1);
        }
    }
    for(i = 0; i < NUM_THREADS; i++){
        pthread_join(thread[i], NULL);
    }
    return 0;
}

