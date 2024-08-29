#include <stdio.h>

void printbinary(int n){
	char arr[32] = {0};
	int i = 0;
	while(n){
		arr[i++] = (n % 2);
		n /= 2;
	}
	for(int j = 31; j >= 0; j--){
		printf("%d", arr[j]);
	}
	printf("\n");
}

int invert(int x, int p, int n){
	int y = (~(~0 << n))<<p;
	return x ^ y;
}

int bitAnd(int x, int y){
	return ~(~x | ~y);
}

int bang(int x){
	return ((x | ((~x + 1)>>31)) & 1) ^ 1;
}

int conditional(int x, int y, int z){
	return (((!!x<<31>>31) & y)  + ((!x<<31>>31) & z));
}

int main(){
	int x = invert(97, 2, 4);
	printbinary(97);
	printbinary(x);
	
	int testand = bitAnd(40, 59);
	printbinary(40);
	printbinary(59);
	printbinary(testand);

	int testbang = bang(98);
	int testbang2 = bang(0);
	printf("%d\n", testbang);
	printf("%d\n",testbang2);

	int testconditional = conditional(0, 54, 10);
	int testconditional2 = conditional(8, 54, 10);
	printf("%d\n", testconditional);
	printf("%d\n", testconditional2);

	return 0;
}
