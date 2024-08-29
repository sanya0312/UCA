#include <stdio.h>
#include <stdlib.h>

int maxPathSum(int **grid, int i, int j, int n, int m) {
    if (i >= n || j >= m) return 0;
    int temp = grid[i][j];
    if (i == n - 1 && j == m - 1) return temp;
    int right = temp + maxPathSum(grid, i, j + 1, n, m);
    int down = temp + maxPathSum(grid, i + 1, j, n, m);
    return (right > down) ? right : down;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int **grid = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        grid[i] = (int *)malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %d", &grid[i][j]);
        }
    }
    int ans = maxPathSum(grid, 0, 0, n, m);
    printf("%d\n", ans);

    return 0;
}

