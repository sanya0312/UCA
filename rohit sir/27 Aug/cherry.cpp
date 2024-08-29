#include <bits/stdc++.h>
using namespace std;

int maxPathSum(vector<vector<char>> grid, int i, int j){
	if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 'x') return 0;
	int temp = grid[i][j] - '0';
	if(i == grid.size() - 1 && j == grid.size() - 1) return temp;
        int right = temp + maxPathSum(grid, i, j + 1);
	int down = temp + maxPathSum(grid, i + 1, j);
	return max(right, down);
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<char>> grid(n, vector<int>(m, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> grid[i][j];
		}
	}
	int ans = maxPathSum(grid, 0, 0);
	cout << ans;
	return 0;
}
