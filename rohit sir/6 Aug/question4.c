#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	scanf("%d", &n);
	int *nums = (int*) malloc(n * sizeof(int));

	for(int i = 0; i < n; i++) scanf("%d", &nums[i]);

	int s = 0;
	int e = n - 1;
	int mid;

	while(s < e){
		int mid = (s + e) / 2;
		if(nums[mid] < nums[mid + 1]){
			s = mid + 1;
		} else e = mid;
	}
	printf("\n%d", nums[s]);
	return 0;
}
