/*
[boj] 17472. 다리 만들기2
한 다리의 방향이 중간에 바뀌면 안되고 다리의 길이는 2이상이어야 한다.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int map[11][11], tmp_map[11][11];
bool visited[11][11];
int n, m, ans, cnt;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
vector<pair<pair<int, int>, int> > land;
int bridge[11][11];
void bfs(int i, int j, int section)
{
	queue<pair<int, int> > qp;
	qp.push(make_pair(i, j));
	tmp_map[i][j] = section;
	while (!qp.empty()) {
		int x = qp.front().first, y = qp.front().second;
		qp.pop();
		for (int i = 0; i < 4; i++) {
			int mx = x + dir[i][0], my = y + dir[i][1];
			if (mx < 0 || my < 0 || mx >= n || my >= m) continue;
			if (map[mx][my] != 1 || map[mx][my] == 0) continue;
			if (tmp_map[mx][my] == section) continue;
			tmp_map[mx][my] = section;
			qp.push(make_pair(mx, my));
		}
	}
}
void print_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << tmp_map[i][j] << " ";
		}
		cout << "\n";
	}
}
void dfs(int i, int j, int section) {
}
void solve()
{
	cnt = 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && !tmp_map[i][j]) {
				land.push_back(make_pair(make_pair(i, j), cnt));
				bfs(i, j, cnt++);
			}
		}
	}
	cout << "\n";
	print_map();
	for (int i = 0; i < land.size(); i++) {
		dfs(land[i].first.first, land[i].first.second, land[i].second);
	}
}
int main()
{
    io;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	cout << ans << "\n";
	return 0;
}