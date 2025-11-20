#include<bits/stdc++.h>
using namespace std;

bool sphenic(int n) {
	int count = 0;
	if(n % 2 == 0) {
		int cnt2 = 0;
		while(n % 2 == 0) {
	    	cnt2++;
	    	if(cnt2 > 1) return false;
	    	n /= 2;
		}
		count++;
	}
	int i = 3;
	while(i * i <= n) {
		int cnti = 0;
		if(n % i == 0) {
			while(n % i == 0) {
				cnti++;
				if(cnti > 1) return false;
				n /= i;
			}
			count++;
		}
		if(count > 3) return false;
		i += 2;
	}
	if(n > 1) count++;
	return count == 3;
}

int main() {
    int t; cin >> t;
    while(t--) {
    	int n; cin >> n;
    	cout << (sphenic(n) ? 1 : 0) << endl;
	}
    return 0;
}