#include "header1.h"

int max(int a, int b){
	return a > b ? a : b;
}

int min(int a, int b){
	return a < b ? a : b;
}

int modulus(int a, int b){
	return a % b;
}

int abs(int a){
	return a >= 0 ? a : -1 * a;
}
