/*
[boj] 17836. 공주님을 구해라
*/
#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int n, m, t, ans = 987654321, gx, gy;
int map[101][101];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
bool visited[101][101];
struct obj {
	int x, y, move;
};
int bfs(int get) {
	int ret = 987654321;
	queue<obj> q;
	q.push({ 0,0,0 });
	visited[0][0] = true;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		int cnt = q.front().move;
		q.pop();
		if (get) {
			if (x == gx && y == gy) {
				if (ret > cnt) {
					ret = cnt;
					continue;
				}
			}
		}
		else {
			if (x == n - 1 && y == m - 1) {
				if (ret > cnt) {
					ret = cnt;
					continue;
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int mx = x + dir[i][0], my = y + dir[i][1];
			if (mx < 0 || my < 0 || mx >= n || my >= m) continue;
			if (visited[mx][my]) continue;
			if (map[mx][my] == 1) continue;
			if (map[mx][my] == 0) {
				visited[mx][my] = true;
				q.push({ mx,my,cnt + 1 });
			}
		}
	}

	return ret;
}
int main()
{
	io;
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				gx = i, gy = j;
			}
		}
	}
	
	int a = bfs(0);
	memset(visited, 0, sizeof(visited));
	int b = bfs(1);
	b += abs(gx - (n - 1)) + abs(gy - (m - 1));
	if (a <= t || b <= t) {
		if (a < b) cout << a << "\n";
		else cout << b << "\n";
	}
	else cout << "Fail\n";
	

	return 0;
}
/*
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int n, m, t, ans = 987654321;
int map[101][101];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
bool visited[101][101];
struct obj {
	int x, y, move;
};
void bfs() {
	queue<obj> q;
	q.push({ 0,0,0 });
	visited[0][0] = true;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		int cnt = q.front().move;
		q.pop();
		if (x == n - 1 && y == m - 1 && cnt <= t) {
			if (ans > cnt) {
				ans = cnt;
			}
		}
		for (int i = 0; i < 4; i++) {
			int mx = x + dir[i][0], my = y + dir[i][1];
			if (mx < 0 || my < 0 || mx >= n || my >= m) continue;
			if (visited[mx][my]) continue;
			if (map[mx][my] == 1) continue;
			if (map[mx][my] == 0) {
				visited[mx][my] = true;
				q.push({ mx,my,cnt + 1 });
			}else if(map[mx][my] == 2) {
				int dis = abs(mx - (n - 1)) + abs(my - (m - 1));
				if (ans > cnt + dis + 1) {
					ans = cnt + dis + 1;
				}
			}
		}
	}
}
int main()
{
	io;
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	bfs();
	if (ans == 987654321) cout << "Fail\n";
	else cout << ans << "\n";
	return 0;
}
*/