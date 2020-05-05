/*
[boj] 17142. 연구소3
비활성화 바이러스는 벽처럼 처리해야함
94% ;;
문제 자체를 제대로 이해못해서 많이 틀린 문제;;;;
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int INF = 1e10;
int n, m, ans = INF, k, cnt;
int map[50][50];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
struct virus {
	int x, y;
};
virus vs[10], tvs[10];
bool visited[10];
void bfs() {
	queue<virus> q;
	int lvisited[50][50];
	int max = 0, infect = 0;
	memset(lvisited, -1, sizeof(lvisited));
	for (int i = 0; i < m; i++) {
		int tx = tvs[i].x, ty = tvs[i].y;
		q.push({ tx, ty });
		lvisited[tx][ty] = 0;
	}

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int mx = x + dir[i][0], my = y + dir[i][1];
			if (mx < 0 || my < 0 || mx >= n || my >= n) continue;
			if (lvisited[mx][my] != -1) continue;
			if (map[mx][my] == 1) continue;
			lvisited[mx][my] = lvisited[x][y] + 1;
			if (map[mx][my] == 0) {
				infect++;
				max = lvisited[mx][my];
			}
			q.push({ mx,my });
		}
	}

	if (cnt == infect)
	{
		if (ans > max) {
			ans = max;
		}
	}
}

void solve(int cur, int cnt) {
	if (cnt == m) {
		bfs();
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
			else if (map[i][j] == 0) {
				cnt++;
			}
		}
	}
	solve(0, 0);
	if (ans == INF) cout << "-1\n";
	else cout << ans << "\n";

	return 0;
}
