#include <bits/stdc++.h>
using namespace std;

void find(int m, int s) {
	if(s > 9 * m || s == 0) {
		cout << "-1 -1";
		return;
	}
	vector<int> max;
	int tmax = s;
	while(tmax >= 9) {
		max.push_back(9);
		tmax -= 9;
	}
	if(tmax > 0) max.push_back(tmax);
	int a = m - max.size();
	while(a--) {
		max.push_back(0);
	}
	vector<int> min;
	min.push_back(1);
	int b = m - 1;
	while(b--) {
		min.push_back(0);
	}
	int tmin = 1;
	for(int i = m - 1; i >= 0; i--) {
		while(tmin < s && min[i] < 9) {
			min[i]++; tmin++;
		}
		if(tmin == s) break;
	}
	for(int x : min) {
		cout << x;
	}
	cout << " ";
	for(int x : max) {
		cout << x;
	}
}

int main() {
	int m, s; cin >> m >> s;
	find(m, s);
	return 0;
}