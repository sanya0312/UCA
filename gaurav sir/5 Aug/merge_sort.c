#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void merge(int arr[], int aux[], int s, int e, int mid){
	for(int k = s; k <= e; k++){
		aux[k] = arr[k];
	}
	int i = s;
	int j = mid + 1;
	for(int k = s; k <= e; k++){
		if(i > mid) arr[k] = aux[j++];
		else if( j > e) arr[k] = aux[i++];
		else if(aux[i] < aux[j]) arr[k] = aux[i++];
		else arr[k] = aux[j++];
	}
}

void mergeSort_recursive(int arr[], int aux[], int s, int e){
	if(s >= e) return;
	int mid = (s + e) / 2;
	mergeSort_recursive(arr, aux, s, mid);
	mergeSort_recursive(arr, aux, mid + 1, e);
	merge(arr, aux, s, e, mid);
}

void mergeSort(int arr[], int n){
	int* aux = (int *) malloc(n * sizeof(int));
	mergeSort_recursive(arr, aux, 0, n -1);
	free(aux);
}

long long time_elapsed(int n){
	int *arr = (int *) malloc(n * sizeof(int));

	srand(time(NULL));
	for(int i = 0; i < n; i++) arr[i] = rand();
	
	struct timeval before;
	gettimeofday(&before, NULL);
	long long before_millis = before.tv_sec*1000LL + before.tv_usec/1000;

	mergeSort(arr, n);

	struct timeval after;
	gettimeofday(&after, NULL);
	long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000;

	return after_millis - before_millis;
}


void test_simple_input() {
	int input[] = {5, 3, 1, 9, 7};
	int expected_output[] = {1, 3, 5, 7, 9};
	mergeSort(input, 5);
	for(int i = 0; i < 5; i++) {
		printf("%d\n", input[i]);
		assert(input[i] == expected_output[i]);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int arr[100000];	

	printf("Before Sorting\n");
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		printf("%d ", arr[i]);
	}	
	mergeSort(arr, n);
	
	printf("\nSorted array\n");
	for(int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	test_simple_input();

	long long t1 = time_elapsed(64000);
	long long t2 = time_elapsed(128000);

	printf("%lf", t2*1.0/t1);
	return 0;
}
