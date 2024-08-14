#include<stdio.h>
int compareAsc(int a, int b){
    return a > b;
}
int compareDesc(int a, int b){
    return b > a;
}
void sort(int arr[], int size, int (*compare)(int, int)){
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(compare(arr[i], arr[j])){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void printarr(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}
int main(){
    int arr[5] = {1,3,2,7,4};
    printarr(arr, 5);
    printf("\n");
    sort(arr, 5, compareAsc);
    printarr(arr, 5);
    printf("\n");
    sort(arr, 5, compareDesc);
    printarr(arr, 5);
    return 0;
};
