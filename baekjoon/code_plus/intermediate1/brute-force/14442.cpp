/*
[boj] 14442. 벽 부수고 이동하기 2
*/
#include <cstdio>
#include <queue>
#include <algorithm>
#pragma warning (disable: 4996)
using namespace std;
int n, m, k, ans = -1;
int map[1001][1001];
bool visited[1001][1001][11];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
/*
struct player {
	int x, y, k, t;
	player(int _x, int _y, int _k, int _t) :x(_x), y(_y), k(_k), t(_t) {};
};
*/
void bfs()
{
	//queue<player> q;
	//q.push(player(0, 0, k, 1));
	queue<pair<pair<int, int>, pair<int, int> > > qp;
	qp.push(make_pair(make_pair(0, 0), make_pair(k, 1)));
	while (!qp.empty()) {
		int x = qp.front().first.first, y = qp.front().first.second;
		int crash = qp.front().second.first, move_cnt = qp.front().second.second;
		qp.pop();
		if (x == n - 1 && y == m - 1) {
			ans = max(ans, move_cnt);
			return;
		}
		for (int i = 0; i < 4; i++) {
			int mx = x + dir[i][0], my = y + dir[i][1];
			if (mx < 0 || my < 0 || mx >= n || my >= m) continue;
			if (map[mx][my] == 1 && crash == 0) continue;
			if (map[mx][my] == 1) {
				//q.push(player(mx, my, crash - 1, move_cnt + 1));
				if (!visited[mx][my][crash]) {
					visited[mx][my][crash] = true;
					qp.push(make_pair(make_pair(mx, my), make_pair(crash - 1, move_cnt + 1)));
				}
			}
			else {
				//q.push(player(mx, my, crash, move_cnt + 1));
				if (!visited[mx][my][crash]) {
					visited[mx][my][crash] = true;
					qp.push(make_pair(make_pair(mx, my), make_pair(crash, move_cnt + 1)));
				}
			}
		}
	}
}
int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	bfs();
	printf("%d\n", ans);
	return 0;
}