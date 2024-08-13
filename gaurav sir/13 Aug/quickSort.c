#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include <time.h>

void swap(int arr[], int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void quickSortRecursive(int arr[], int left, int right){
	if(left >= right) return;

	int pivot = arr[left];
	int i = left + 1;

	for(int j = left + 1; j <= right; j++){
		if(arr[i] < pivot)
			swap(arr, i++, j);
	}
	swap(arr, left, --i);
	quickSortRecursive(arr, left, i - 1);
	quickSortRecursive(arr, i + 1, right);

}

void quickSort(int arr[], int n){
	quickSortRecursive(arr, 0, n - 1);
}

long long time_elapsed(int n){
        int *arr = (int *) malloc(n * sizeof(int));

        srand(time(NULL));
        for(int i = 0; i < n; i++) arr[i] = rand();

        struct timeval before;
        gettimeofday(&before, NULL);
        long long before_millis = before.tv_sec*1000LL + before.tv_usec/1000;

        quickSort(arr, n);

        struct timeval after;
        gettimeofday(&after, NULL);
        long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000;

        return after_millis - before_millis;
}

void test_simple_input() {
        int input[] = {5, 3, 1, 9, 7};
        int expected_output[] = {1, 3, 5, 7, 9};
        quickSort(input, 5);
        for(int i = 0; i < 5; i++) {
                printf("%d\n", input[i]);
                assert(input[i] == expected_output[i]);
        }
}

int main(){
        /*int n;
        scanf("%d", &n);
        int arr[100000];

        printf("Before Sorting\n");
        for(int i = 0; i < n; i++){
                scanf("%d", &arr[i]);
                printf("%d ", arr[i]);
        }
        quickSort(arr, n);

        printf("\nSorted array\n");
        for(int i = 0; i < n; i++)
                printf("%d ", arr[i]);
*/
        test_simple_input();

        long long t1 = time_elapsed(64000);
        long long t2 = time_elapsed(128000);

        printf("%lf", t2*1.0/t1);
        return 0;
}


