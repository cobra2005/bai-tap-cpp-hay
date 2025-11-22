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
		int top = 0, bottom = n - 1;
		int left = 0, right = m - 1;
		while(top <= bottom && left <= right) {
			for(int i = left; i <= right; i++) cout << a[top][i] << " ";
			top++;
			for(int i = top; i <= bottom; i++) cout << a[i][right] << " ";
			right--;
			if(top <= bottom) {
				for(int i = right; i >= left; i--) cout << a[bottom][i] << " ";
				bottom--;	
			}
			if(left <= right) {
				for(int i = bottom; i >= top; i--) cout << a[i][left] << " ";
				left++;	
			}
		}
		cout << endl;
	}
    return 0;
}
