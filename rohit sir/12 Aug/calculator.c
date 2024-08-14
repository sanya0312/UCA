#include <stdio.h>

int add(int a, int b){
	return a + b;
}
int subtract(int a, int b){
	return b - a;
}
int multiply(int a, int b){
	return a * b;
}
int divide(int a, int b){
	if(b == 0) return 0;
	return a / b;
}
void performOperations(int (*operation)(int,int), int a, int b){
	int ans = operation(a, b);
	printf("%d\n", ans);
}
int main(){
	int first, second;
	scanf("%d %d", &first, &second);

	performOperations(add, first, second);
	performOperations(subtract, first, second);
	performOperations(multiply, first, second);
	performOperations(divide, first, second);
	return 0;
}
