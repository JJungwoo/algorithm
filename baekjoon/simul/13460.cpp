/*
[boj] 13460. 구슬 탈출2
*/
#include <iostream>
#include <queue>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, m, ans = 987654321;
char map[11][11];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
bool visited[11][11][11][11];
struct ball {
	int rx, ry, bx, by, cnt;
	ball(int _rx, int _ry, int _bx, int _by, int _cnt) : rx(_rx), ry(_ry), bx(_bx), by(_by), cnt(_cnt) {};
};
void move_ball(int &x, int &y, int &cnt, int xdir, int ydir) {
	while (map[x + xdir][y + ydir] != '#' && map[x][y] != 'O') {
		x += xdir;
		y += ydir;
		cnt++;
	}
}
void bfs(int a, int b, int c, int d) {
	queue<ball> q;
	q.push(ball(a, b, c, d, 0));
	while (!q.empty()) {
		int rx = q.front().rx, ry = q.front().ry;
		int bx = q.front().bx, by = q.front().by;
		int tcnt = q.front().cnt;
		q.pop();
		if (tcnt >= 10) {
			return;
		}
//		cout << map[rx][ry] << "," << rx << "," << ry << "," << bx << "," << by << "\n";
		for (int i = 0; i < 4; i++) {
			int mrx = rx, mry = ry, mbx = bx, mby = by;
			int rcnt = 0, bcnt = 0;
			move_ball(mrx, mry, rcnt, dir[i][0], dir[i][1]);
			move_ball(mbx, mby, bcnt, dir[i][0], dir[i][1]);
			if (map[mbx][mby] == 'O') continue;
			//cout << map[mrx][mry] << "," << mrx << "," << mry << ","
			//	<< map[mbx][mby] << "," << mbx << "," << mby << "\n";
			if (map[mrx][mry] == 'O') {
				if (ans > tcnt + 1) {
					ans = tcnt + 1;
				}
				return;
			}
			if (mrx == mbx && mry == mby) {
				if (rcnt > bcnt) mrx -= dir[i][0], mry -= dir[i][1];
				else mbx -= dir[i][0], mby -= dir[i][1];
			}
			if (visited[mrx][mry][mbx][mby]) continue;
			visited[mrx][mry][mbx][mby] = true;
			q.push(ball(mrx, mry, mbx, mby, tcnt + 1));
		}
	}
}
int main()
{
	io;
	cin >> n >> m;
	int rx, ry, bx, by;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				rx = i, ry = j;
			}
			else if (map[i][j] == 'B') {
				bx = i, by = j;
			}
		}
	}
	visited[rx][ry][bx][by] = true;
	bfs(rx, ry, bx, by);
	if(ans != 987654321) cout << ans << "\n";
	else cout << "-1\n";
	return 0;
}