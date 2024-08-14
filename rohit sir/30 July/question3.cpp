#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
int main(){
int r, c;
cin >> r>> c;
vector<int> rowsum(r, 0);
vector<int> colsum(c, 0);
for(int i = 0; i < r; i++) cin >> rowsum;
for(int j = 0; j < c; j++) cin >> colsum;

vector<vector<int>> ans(r, vector<int> c);

for(int i = 0; i < r; i++){
for(int j = 0; j < c; j++){
ans[i][j] = min(rowsum[i], colsum[j]);
rowsum[i] -= ans[i][j];
colsum[j] -= ans[i][j];
}
}

for(int i = 0; i < r; i++){
for(int j = 0; j < c; j++){
cout << ans[i][j];
}
}
return 0;
}
