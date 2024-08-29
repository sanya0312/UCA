#include <stdio.h>
#include "header1.h"
#include "header2.h"

int main(){
	int a, b;
	printf("Enter a and b: ");
	scanf("%d %d", &a, &b);
	printf("Adding a and b: %d\n", add(a, b));
	printf("Subtracting b from a: %d\n", subtract(a, b));
	printf("Multiplying a and b: %d\n", multiply(a, b));
	printf("dividing a and b: %d\n", divide(a, b));
	printf("Modulus of a and b: %d\n", modulus(a, b));
	printf("Maximum of a and b: %d\n", max(a, b));
	printf("Minimum of a and b: %d\n", min(a, b));
	printf("Abs value of a: %d\n", abs(a));
	return 0;
}
