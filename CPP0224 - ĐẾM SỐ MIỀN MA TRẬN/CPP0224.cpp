#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[101][101];
bool visited[101][101];

// Cần hiểu về thuật toán DFS/BFS trước khi giải bài tập này

// 8 directions
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1}; 

void dfs(int x, int y) {
	visited[x][y] = true;
	for(int k = 0; k < 8; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
			if(!visited[nx][ny] && a[nx][ny] == 1) {
				dfs(nx, ny);
			}
		}
	}
}

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({x, y});
	visited[x][y] = true;
	while(!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		int cx = p.first, cy = p.second;
		for(int k = 0; k < 8; k++) {
			int nx = cx + dx[k];
			int ny = cy + dy[k];
			if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if(!visited[nx][ny] && a[nx][ny] == 1) {
					visited[nx][ny] = true;
					q.push({nx, ny});
				}
			}
		}
	}
}

int main() {
    int t; cin >> t;
    while(t--) {
    	cin >> n >> m;
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < m; j++) {
    			cin >> a[i][j];
    			visited[i][j] = false;
			}
		}
		int count = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(!visited[i][j] && a[i][j] == 1) {
					count++;
					bfs(i, j);
				}
			}
		}
		cout << count << endl;
	}
    return 0;
}