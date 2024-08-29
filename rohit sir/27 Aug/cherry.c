#include <stdio.h>
#include <stdlib.h>

int maxPathSum(char **grid, int i, int j, int n, int m, int** dp) {
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 'x') return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int temp = grid[i][j] - '0';
    if (i == n - 1 && j == m - 1) return dp[i][j] = temp;
    int right = temp + maxPathSum(grid, i, j + 1, n, m, dp);
    int down = temp + maxPathSum(grid, i + 1, j, n, m, dp);
    return dp[i][j] = (right > down) ? right : down;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char **grid = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        grid[i] = (char *)malloc(m * sizeof(char));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &grid[i][j]);
        }
    }
    
    int **dp = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        dp[i] = (int *)malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = -1;
        }
    }

    int ans = maxPathSum(grid, 0, 0, n, m, dp);
    printf("%d\n", ans);

    return 0;
}

