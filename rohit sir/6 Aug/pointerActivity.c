#include <stdio.h>
int main(){
	int a = 130;
	int* b = &a;
	char* c = &a;
	printf("%d\n", *c);
	printf("%d", *b);
	return 0;
}
