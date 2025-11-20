#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    long long res = 0, run = 1;
    for(int i = 1; i < n; i++) {
    	if(s[i] == s[i - 1]) run++;
    	else {
    		res += (run * (run - 1) / 2);
    		run = 1;
		}
	}
	res += (run * (run - 1) / 2);
	cout << res;
    return 0;
}