#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> fruits(n);
    for(int i = 0; i < n; i++){
    	cin >> fruits[i];
    }
    unordered_map<int,int> mpp;
    int ans = 0, i = 0, j = 0;
    while(j < n){
    	mpp[fruits[j]]++;
	if(mpp.size() > 2){
	    while(mpp.size() > 2){
	        mpp[fruits[i]]--;
		if(mpp[fruits[i]] == 0) mpp.erase(fruits[i]);
	    	i++;
	    }
	}
	ans = max(ans, j - i + 1);
	j++;
    }
    cout<<ans;
    return 0;
}

