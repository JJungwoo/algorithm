/*
[boj] 17142. 연구소3
비활성화 바이러스는 벽처럼 처리해야함
94% ;;

*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int INF = 1e10;
int n, m, ans = INF, k;
int map[50][50], copymap[50][50];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
struct virus {
	int x, y;
};
virus vs[10], tvs[10];
bool visited[10];
void copy_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				copymap[i][j] = -1;
			}
			else if (map[i][j] == 2) {
				copymap[i][j] = -2;
			}
			else {
				copymap[i][j] = -3;
			}
		}
	}
}
int bfs() {
	queue<virus> q;
	bool lvisited[50][50];
	int max = 0;
	memset(lvisited, 0, sizeof(lvisited));
	for (int i = 0; i < m; i++) {
		int tx = tvs[i].x, ty = tvs[i].y;
		q.push({ tx, ty });
		lvisited[tx][ty] = true;
		copymap[tx][ty] = 0;
	}

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		q.pop();
		if (copymap[x][y] > max) {
			max = copymap[x][y];
		}
		for (int i = 0; i < 4; i++) {
			int mx = x + dir[i][0], my = y + dir[i][1];
			if (mx < 0 || my < 0 || mx >= n || my >= n) continue;
			if (lvisited[mx][my]) continue;
			if (copymap[mx][my] != -1) continue;
			
			if (copymap[mx][my] == -3) {
				copymap[mx][my] = copymap[x][y] + 1;
			}
			
			lvisited[mx][my] = true;
			q.push({ mx,my });
		}
	}
	return max;
}
void print() {
	cout << "print\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << copymap[i][j] << " ";
		}
		cout << "\n";
	}
}
void solve(int cur, int cnt) {
	if (cnt == m) {
		int res = 0;
		copy_map();
		res = bfs();
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (copymap[i][j] == -3) {
					res = -1;
					return;
				}
			}
		}
		//print();
		if (ans > res) {
			ans = res;
		}
		return;
	}
	
	for (int i = cur; i < k; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		tvs[cnt] = vs[i];
		solve(i+1, cnt + 1);
		tvs[cnt] = { 0,0 };
		visited[i] = false;
	}
}
int main()
{
	io;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				vs[k++] = { i,j };
			}
		}
	}
	solve(0, 0);
	if (ans == INF) cout << "-1\n";
	else cout << ans << "\n";

	return 0;
}
