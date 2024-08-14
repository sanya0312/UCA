#include <iostream>
#include <string>
#include <unordered_map>
#include <math.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	int n = s.size();
	int i = 0, j = 0;
	int ans = 0;
	unordered_map<char, int> mpp;
	while(j < n){
		mpp[s[j]]++;
		if(mpp.size() > 2){
			while(mpp.size() > 2){
				mpp[s[i]]--;
				if(mpp[s[i]] == 0){
					mpp.erase(s[i]);
				}
				i++;
			}
		}
		ans = max(ans, j - i + 1);
		j++;
	}
	cout << ans;
	return 0;
}
