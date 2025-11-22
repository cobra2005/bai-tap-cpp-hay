#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
    	int n, m; cin >> n >> m;
    	int a[n][m];
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < m; j++) {
    			cin >> a[i][j];
			}
		}
		int layers = (m < n ? m : n) / 2;
		for(int layer = 0; layer < layers; layer++) {
			vector<int> v;
			int top = layer;
			int left = layer;
			int bottom = n - 1 - layer;
			int right = n - 1 - layer;
			for(int i = left; i <= right; i++) v.push_back(a[top][i]);
			for(int i = top + 1; i <= bottom; i++) v.push_back(a[i][right]);
			if(bottom > top) {
				for(int i = right - 1; i >= left; i--) v.push_back(a[bottom][i]);
			}
			if(left < right) {
				for(int i = bottom - 1; i > top; i--) v.push_back(a[i][left]);
			}
			rotate(v.rbegin(), v.rbegin() + 1, v.rend());
			int idx = 0;
			for(int i = left; i <= right; i++) a[top][i] = v[idx++];
			for(int i = top + 1; i <= bottom; i++) a[i][right] = v[idx++];
			if(bottom > top) {
				for(int i = right - 1; i >= left; i--) a[bottom][i] = v[idx++];
			}
			if(left < right) {
				for(int i = bottom - 1; i > top; i--) a[i][left] = v[idx++];
			}
		}
		for(int i = 0; i < n; i++) {
    		for(int j = 0; j < m; j++) {
    			cout << a[i][j] << " ";
			}
		}
    cout << endl;
	}
    return 0;
}