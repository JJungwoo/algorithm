/*
[boj] 14503. 로봇 청소기
현재 위치를 청소한다.
현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색한다.

*/
/*
#include <iostream>
#include <vector>

#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, m, ans;
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int map[50][50];
struct robot {
	int x, y, d;	// 0 북, 1 동, 2 남, 3 서
};
robot my;
void solve() {
	while (true) {

	}
}
int main()
{
	io;
	cin >> n >> m;
	cin >> my.x >> my.y >> my.d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	cout << ans << "\n";
	return 0;
}
*/