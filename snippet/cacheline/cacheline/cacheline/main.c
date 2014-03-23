//
//  main.c
//  cacheline
//
//  Created by 吴洋 on 14-3-22.
//  Copyright (c) 2014年 吴洋. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

unsigned long long int rdtscp(void)
{
    unsigned a, d;
    
    __asm__ volatile("rdtscp" : "=a" (a), "=d" (d));
    
    return ((unsigned long long)a) | (((unsigned long long)d) << 32);;
}

long long int get_time_stamp(){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec*1000000LL + tv.tv_usec;
}

void test1(){
    int size = 640*1024*1024;
    int*a1 = (int *)malloc(sizeof(int)*size);
    long long int t = get_time_stamp();
    for(int i = 0; i <size; i++){
        a1[i] += 3;
    }
    printf("use time %lld\n", get_time_stamp() - t);
    free(a1);
    
    int*a2 = (int *)malloc(sizeof(int)*size);
    t = get_time_stamp();
    for(int i = 0; i <size; i += 32){
        a2[i] += 3;
    }
    printf("use time %lld\n", get_time_stamp() - t);
    free(a2);
}

int main(int argc, const char * argv[])
{

    test1();
    return 0;
}

