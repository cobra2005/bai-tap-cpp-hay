#include <bits/stdc++.h>
using namespace std;

bool prime[1000001];
vector<int> v;

void sang() {
	for(int i = 0; i <= 1000000; i++) prime[i] = true;
	prime[0] = prime[1] = false;
	for(int i = 2; i * i <= 1000000; i++) {
		if(prime[i]) {
			for(int j = i * i; j <= 1000000; j += i) prime[j] = false;
		}
	}
}

void init() {
	sang();
	v.push_back(2);
	for(int i = 3; i <= 1000000; i += 2) {
		if(prime[i]) v.push_back(i);
	}
}

void search(int n) {
	for(int i = 0; i < v.size(); i++) {
		if(binary_search(v.begin() + i, v.end(), n - v[i])) {
			cout << v[i] << " " << n - v[i] << "\n";
			return;
		}
	}
	cout << "-1\n";
}

int main() {
	init();
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		search(n);
	}
	return 0;
}
