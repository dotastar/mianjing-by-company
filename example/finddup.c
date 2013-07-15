#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 10000

/*
 * Array A size is 10001, has all number from 1 to 10000, find the dup
 * */
 
/*use hash*/ 
int find_dup1(int a[], int n){
	int* hash = (int *)malloc(n*sizeof(int));
	int result = 0;
	int i = 0;
	for(;i < n; ++i){
		hash[i] = 0; //or use memset()
	}
	for(i = 0; i < n; ++i){
		if(hash[a[i]] == 1) {
			result = a[i];
			break;
		} else {
			hash[a[i]] = 1;
		}
	}
	free(hash);
	return result;
}
//use sum
int find_dup2(int a[], int n){
	int i = 0, result = 0;
	for(; i < n; ++i){
		result += a[i] - i;
	}
	return result;
}

//use xor
int find_dup3(int a[], int n){
	int i = 0, result = 0;
	for(; i < n; ++i){
		result ^= a[i];
		result ^= i;
	}
	return result;
}

//use swap
int find_dup4(int a[], int n){
	int *b = (int *)malloc(n*sizeof(int));
	memcpy(b, a, n*sizeof(int));
	int result = b[0];
	while(result != b[result]){
		int t = result;
		result = b[result];
		b[t] = t;
	}
	free(b);
	return result;
}

//if sorted, use binary search
int compare(const void *a, const void *b){
	return (*(int *)a - *(int *)b);
}
int find_dup5(int a[], int n){
	int *b = (int *)malloc(n*sizeof(int));
	memcpy(b, a, n*sizeof(int));
	qsort(b, n, sizeof(int), compare);
	int result = b[0], low = 0, high = n-1;
	while(low <= high){
		int mid = low + (high - low)/2;
		if(b[mid] == b[mid+1]){
			result = b[mid];
			break;
		}
		if(mid == b[mid]){
			high = mid;
		} else {
			low = mid;
		}
	}
	free(b);
	return result;
}

int main(int argc, char **argv)
{
	srand(time(NULL));
	int a[N+1] = {0};
	int i = 1;
	for(;i <= N; ++i){
		a[i] = i;
	}
	a[0] = rand()%N + 1;
	printf("dup is %d\n", a[0]);
	for(i = 0; i < N; ++i){
		int j = rand()%(N - i) + 1+i;
		int t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	printf("use hash find %d\n", find_dup1(a, N+1));
	printf("use sum find %d\n", find_dup2(a, N+1));
	printf("use xor find %d\n", find_dup3(a, N+1));
	printf("use swap find %d\n", find_dup4(a, N+1));
	printf("use binary search find %d\n", find_dup5(a, N+1));
	return 0;
}
