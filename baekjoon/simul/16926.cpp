/*
[boj] 16926. 배열 돌리기1
*/
#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, m, r;
int state = 0, nstate = 1;
int map[301][301][2];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
void print(int tmp[301][301][2])
{
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << tmp[i][j][state] << " ";
		}
		cout << "\n";
	}
}
void solve()
{
	while (r--) {
		int i = 1, j = 1, tn = n, tm = m;
		while (i <= n / 2 && j <= m / 2) {
			int tmp = r;
			int ti = i, tj = j, d = 0;
			do {
				int nx = ti + dir[d][0], ny = tj + dir[d][1];
				if (nx < i || ny < j || nx > tn || ny > tm) d++;
				else {
					map[nx][ny][nstate] = map[ti][tj][state];
					ti = nx, tj = ny;
				}
			} while (!(ti == i && tj == j));
			i++, j++;
			tn--, tm--;
		}
		state = (state + 1) % 2;
		nstate = (state + 1) % 2;
	}
}
int main()
{
	io;
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j][0];
		}
	}
	//int mod = (n * 2) + ((m - 2) * 2);
	//r = (r % mod);
	//cout << r << "," << mod << "\n";
	solve();
	print(map);
	return 0;
}
