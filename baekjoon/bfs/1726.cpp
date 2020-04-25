/*
[boj] 1726. 로봇
다시 한번 풀어보기.. 좋은 bfs문제인데 실수를 너무 많이했다.;
*/
#include <iostream>
#include <queue>
#include <cmath>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int m, n, ans = 987654321;
int map[100][100];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };	// 동, 서, 남, 북
bool visited[100][100][4];
struct robot {
	int x, y, d, cnt;
};
robot sspot, espot;
int solve() {
	queue<robot> q;
	q.push({ sspot.x, sspot.y, sspot.d, 0 });
	visited[sspot.x][sspot.y][sspot.d] = 1;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		int d = q.front().d, cnt = q.front().cnt;
		q.pop();
		if (x == espot.x && y == espot.y && d == espot.d) {
			return cnt;
		}
		//for (int t = 3; t >= 1; t--) {
		for (int t = 1; t <= 3; t++) {
			int mx = x + (dir[d][0] * t), my = y + (dir[d][1] * t);
			if (mx < 0 || my < 0 || mx >= m || my >= n) continue;
			if (visited[mx][my][d]) continue;
			if (map[mx][my] == 1) break;
			visited[mx][my][d] = true;
			q.push({ mx,my,d,cnt + 1 });
		}
		for (int i = 0; i < 4; i++) {
			if (d == i) continue;
			int k = ((d + i) % 4) == 1 ? 2 : 1;
			if (visited[x][y][i]) continue;
			visited[x][y][i] = true;
			q.push({ x,y,i,cnt+k });
		}
	}
}
int main()
{
	io;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	cin >> sspot.x >> sspot.y >> sspot.d;
	sspot.x--, sspot.y--, sspot.d--;
	cin >> espot.x >> espot.y >> espot.d;
	espot.x--, espot.y--, espot.d--;
	ans = solve();
	cout << ans << "\n";
	return 0;
}
