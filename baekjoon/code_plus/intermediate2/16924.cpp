/*
[boj] 16924. 십자가 찾기
맞왜틀;;
*/
#include <iostream>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, m, ans;
char map[100][100];
bool visited[100][100];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int ans_map[100][100][4];
bool end_check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//cout << visited[i][j] << " ";
			if (map[i][j] == '*' && !visited[i][j]) {
				return false;
			}
		}
		//cout << "\n";
	}
	return true;
}
bool check_cross(int x, int y, int s) {
	if (ans_map[x][y][s] || map[x][y] != '*') return false;
	for (int i = 1; i <= s; i++) {
		vector<pair<int, int> > tmp;
		for (int j = 0; j < 4; j++) {
			int mx = x + (dir[j][0] * i), my = y + (dir[j][1] * i);
			if (mx < 0 || my < 0 || mx > n || my > m) continue;
			if (map[mx][my] != '*') return false;
			//cout << mx << " , " << my << "\n";
			tmp.push_back(make_pair(mx, my));
		}
		visited[x][y] = true;
		int size = tmp.size();
		for (int v = 0; v < size; v++) {
			visited[tmp[v].first][tmp[v].second] = true;
		}
	}
	return true;
}
void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int z = 1; z <= 3; z++) {
				if (check_cross(i,j,z)) {
					ans_map[i][j][z] = 1;
					ans++;
				}
			}
		}
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
	if (end_check() && ans) {
		cout << ans << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int z = 1; z <= 3; z++) {
					if (ans_map[i][j][z]){
						cout << i + 1 << " " << j + 1 << " " << z << "\n";
					}
				}
			}
		}
	}
	else {
		cout << "-1\n";
	}
	return 0;
}