#include <stdio.h>
#include <limits.h>
#include <math.h>

int main(){
	int num;
	scanf("%d", &num);
	 int ans = 0;
	 int sign = num > 0? 1 : -1;
	 num = num * sign;

	 while(num){
		int digit = num % 10;
		if((ans >= INT_MAX / 10 - digit)){
                        printf("%d", 0);
                         return 0;
                 }

		ans = ans * 10 + digit;
		num = num / 10;
	 }
	 printf("%d", sign * ans);
	return 0;
}
