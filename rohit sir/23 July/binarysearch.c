#include <stdio.h>

void swap(int a, int b, int arr[]){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void sort(int arr[], int n){
    for(int i = 0; i < n; i++){
	for(int j = i + 1; j < n; j++){
            if(arr[i] > arr[j]) swap(i, j, arr);
	}
    	printf("%d ", arr[i]); 
    }
}


int main(){
    int n;
    printf("Enter the number of elements of array ");
    scanf("%d", &n);
    int k;
    printf("Enter the target value ");
    scanf("%d", &k);

    int arr[n];
    printf("Enter the elements of array: ");
    for(int i = 0; i < n; i++){
    	scanf("%d", &arr[i]);
    }
	
    printf("sorted array ");
    sort(arr, n); 

    int s = 0;
    int e = n - 1;
    
    while(s <= e){
    	int mid = s + (e - s) / 2;
	if(arr[mid] == k){
	    printf("\nindex = %d", mid);
	    return 0;
	}
	else if(arr[mid] < k) s = mid + 1;
	else e = mid - 1;
    }
    printf("Not found");

    return 0;
}
