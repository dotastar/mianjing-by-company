#include <iostream>
#include <time.h>
#include <sys/time.h>

using namespace std;

// #define rdtsc(low,high)                                         \
//     __asm__ __volatile__("rdtsc" : "=a" (low), "=d" (high))

// #define rdtscp(low,high) \
//     __asm__ __volatile__("rdtscp" : "=a" (low), "=d" (high))

/*
  Method         Cost(nanoseconds)    Precision
  gettimeofday   41.49                microsecond
  clock_gettime  107.3                nanosecond
  rdtsc          12.52                clock cycle
  rdtscp         21.43                clock cycle
  clock          141.94               Clock tick
 */

unsigned long long int rdtsc(void)
{
    unsigned long long int x;
    unsigned a, d;

    __asm__ volatile("rdtsc" : "=a" (a), "=d" (d));

    return ((unsigned long long)a) | (((unsigned long long)d) << 32);;
}

unsigned long long int rdtscp(void)
{
    unsigned long long int x;
    unsigned a, d;

    __asm__ volatile("rdtscp" : "=a" (a), "=d" (d));

    return ((unsigned long long)a) | (((unsigned long long)d) << 32);;
}

const int kLoopCount = 1000000000;

void test5(){
    //test clock
    clock_t start, finish;
    double duration;

    start = clock();
    clock_t t;
    for(int i = 0; i < kLoopCount; ++i){
        t = clock();
    }
    finish = clock();
    duration = (double)(finish - start)/CLOCKS_PER_SEC;
    cout<<"clock costs "<<duration<<" nanoseconds"<<endl;
}

void test4(){
    //test rdtscp
    clock_t start, finish;
    double duration;

    start = clock();
    unsigned long long t;
    for(int i = 0; i < kLoopCount; ++i){
        t = rdtscp();
    }
    finish = clock();
    duration = (double)(finish - start)/CLOCKS_PER_SEC;
    cout<<"rdtscp costs "<<duration<<" nanoseconds"<<endl;

}

void test3(){
    //test rdtsc
    clock_t start, finish;
    double duration;

    start = clock();
    unsigned long long t;
    for(int i = 0; i < kLoopCount; ++i){
        t = rdtsc();
    }
    finish = clock();
    duration = (double)(finish - start)/CLOCKS_PER_SEC;
    cout<<"rdtsc costs "<<duration<<" nanoseconds"<<endl;
}

void test2(){
    //test clock_gettime
    clock_t start, finish;
    double duration;

    start = clock();
    struct timespec t;
    for(int i = 0; i < kLoopCount; ++i){
        clock_gettime(CLOCK_MONOTONIC, &t);
    }
    finish = clock();
    duration = (double)(finish - start)/CLOCKS_PER_SEC;
    cout<<"clock_gettime costs "<<duration<<" nanoseconds"<<endl;
}

void test1(){
    // test gettimeofday
    clock_t start, finish;
    double duration;

    start = clock();
    struct timeval t;
    for(int i = 0; i < kLoopCount; ++i){
        gettimeofday(&t, NULL);
    }
    finish = clock();
    duration = (double)(finish - start)/CLOCKS_PER_SEC;
    cout<<"gettimeofday costs "<<duration<<" nanoseconds"<<endl;
}

int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}
