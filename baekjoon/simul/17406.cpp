/*
[boj] 17406. 배열 돌리기4
(r, c, s)
(r+s, c+s)
r: 행 row
c: 열 column
*/

#include <iostream>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, m, k, ans;
int map[51][51], tmp_map[51][51];
struct query {
	int r, c, s;
	query(int _r, int _c, int _s) : r (_r), c (_c), s (_s){};
};
vector<query> vq;
vector<query> tmp_vq;
void init_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp_map[i][j] = map[i][j];
		}
	}
}
void move_map(int r, int c, int s) {
	int dx = r + s - 1, dy = c + s - 1, tx = abs(r - s) - 1, ty = abs(c - s) - 1;
	for (int i = dx - 1; i >= ty; i--) {
		tmp_map[i][dy] = tmp_map[i - 1][dy];
	}
	for (int i = dx; i < ty - 1; i++) {
		tmp_map[i+1][dy] = tmp_map[i][dy];
	}
}
void solve(int cnt) {
	if (cnt == k) {
		init_map();
		for (int i = 0; i < k; i++) {
		}
		return;
	}
	for (int i = 0; i < k; i++) {
		tmp_vq.push_back(vq[i]);
		solve(cnt + 1);
		tmp_vq.pop_back();
	}
}
int main()
{
    io;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		vq.push_back(query(r, c, s));
	}
	solve(0);
	return 0;
}