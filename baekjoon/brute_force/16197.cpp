/*
[boj] 16197. 두 동전
*/
#include <iostream>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int n, m, ans = 987654321;
char map[20][20];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
bool visited[20][20][20][20];
void solve(int x1, int y1, int x2, int y2, int cnt) {
	if (cnt >= 10) {
		return;
	}

	for (int i = 0; i < 4; i++) {
		int end = 0;
		int mx1 = x1 + dir[i][0], my1 = y1 + dir[i][1];
		int mx2 = x2 + dir[i][0], my2 = y2 + dir[i][1];

		if (mx1 < 0 || my1 < 0 || mx1 >= n || my1 >= m) end++;
		if (mx2 < 0 || my2 < 0 || mx2 >= n || my2 >= m) end++;
		if (end == 2) continue;
		else if (end == 1) {
			if (ans > cnt+1) {
				ans = cnt+1;
			}
			continue;
		}

		if (map[mx1][my1] == '#') mx1 = x1, my1 = y1;
		if (map[mx2][my2] == '#') mx2 = x2, my2 = y2;
		if (visited[mx1][my1][mx2][my2]) continue;

		visited[mx1][my1][mx2][my2] = true;
		solve(mx1, my1, mx2, my2, cnt + 1);
		visited[mx1][my1][mx2][my2] = false;
	}
}
int main()
{
	io;
	int x1 = -1, y1, x2, y2;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'o') {
				if (x1 == -1) x1 = i, y1 = j;
				else x2 = i, y2 = j;
			}
		}
	}
	solve(x1, y1, x2, y2, 0);
	if (ans == 987654321) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}