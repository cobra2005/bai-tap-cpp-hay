#include <bits/stdc++.h>
using namespace std;

int n, a[1001];
bool isFirst;

void init() {
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
}

void sinh() {
	int i = n - 1;
	while(i >= 1 && a[i] < a[i + 1]) i--;
	if(i == 0) {
		isFirst = true;
		return;
	}
	int j = n;
	while(a[j] > a[i]) j--;
	swap(a[i], a[j]);
	reverse(a + i + 1, a + n + 1);
}

void run() {
	cin >> n;
	isFirst = false;
	init();
	sinh();
	if(isFirst) {
		for(int i = n; i >= 1; i--) cout << i << " ";
	} else {
		for(int i = 1; i <= n; i++) cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	int t; cin >> t;
	while(t--) {
		run();
	}
	return 0;
}
