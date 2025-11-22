#include<bits/stdc++.h>
using namespace std;

// Nên làm bài CPP0223 - MA TRẬN XOẮN ỐC - 1 trước trước khi làm bài tập này

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
		int top = 0, bottom = n - 1;
		int left = 0, right = m - 1;		
		while(top <= bottom && left <= right) {
			int top1 = top, bottom1 = bottom, left1 = left, right1 = right;
			vector<int> v;
			for(int i = left; i <= right; i++) v.push_back(a[top][i]);
			top++;
			for(int i = top; i <= bottom; i++) v.push_back(a[i][right]);
			right--;
			if(top <= bottom) {
				for(int i = right; i >= left; i--) v.push_back(a[bottom][i]);
				bottom--;
			}
			if(left <= right) {
				for(int i = bottom; i >= top; i--) v.push_back(a[i][left]);
				left++;
			}
			rotate(v.rbegin(), v.rbegin() + 1, v.rend());
			int idx = 0;
			for(int i = left1; i <= right1; i++) a[top1][i] = v[idx++];
			top1++;
			for(int i = top1; i <= bottom1; i++) a[i][right1] = v[idx++];
			right1--;
			if(top1 <= bottom1) {
				for(int i = right1; i >= left1; i--) a[bottom1][i] = v[idx++];
				bottom1--;
			}
			if(left1 <= right1) {
				for(int i = bottom1; i >= top1; i--) a[i][left1] = v[idx++];
				left1++;
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