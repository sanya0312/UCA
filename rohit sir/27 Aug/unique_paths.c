#include <stdio.h>
#include <stdlib.h>
void writePath(int i, int j, int n, int m){
    if(i < 0 || i >= n || j < 0 || j >= m) return;
    if(i == n - 1 && j == m - 1) {
    	printf("%d %d\n Reached End\n", i, j);
	return;
    }
    printf("%d %d -> ", i, j);
    writePath(i + 1, j, n, m);
    writePath(i, j + 1, n, m);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    writePath(0, 0, n, m);
   
    return 0;
}

