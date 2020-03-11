/*
[boj] 15683. 감시
*/
#include <iostream>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
struct pos {
	int x, y, d, s;
	pos(int _x, int _y, int _d, int _s) :x(_x), y(_y), d(_d), s(_s) {};
}; 
int n, m, ans = 987654321, total;
int map[9][9];
bool visited[9][9][6];
vector<pos> cameras;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };		
void copy_map(int tmp[9][9]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = map[i][j];
		}
	}
}
void check_monitering(int x, int y, int d, int tmp[9][9]) {
	int mx = x + dir[d][0], my = y + dir[d][1];
	if (mx < 0 || my < 0 || mx >= n || my >= m) return;
	while (tmp[mx][my] != 6) {
		if (tmp[mx][my] == 0) {
			tmp[mx][my] = 7;
		}
		//cout << "mx:" << mx << ", my:" << my << " = " << tmp[mx][my] << "\n";
		mx += dir[d][0];
		my += dir[d][1];
		if (mx < 0 || my < 0 || mx >= n || my >= m) break;
	}
}
int check_noview(int tmp[9][9]) {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmp[i][j] == 0) {
				ret++;
			}
		}
	}
	return ret;
}
void print_map(int tmp[9][9]) {
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << tmp[i][j] << " ";
		}
		cout << "\n";
	}
}
void solve(int cnt) {
	if (cnt == total) {
		int tmp_map[9][9];
		copy_map(tmp_map);
		int size = cameras.size();
		for (int i = 0; i < size; i++) {
			int x = cameras[i].x, y = cameras[i].y;
			int d = cameras[i].d;
			switch (cameras[i].s) {
			case 1:
				check_monitering(x, y, d, tmp_map);
				break;
			case 2:	// d = 0, 1, // 상0 하1 좌2 우3
				if (d == 0) {
					check_monitering(x, y, 2, tmp_map);
					check_monitering(x, y, 3, tmp_map);
				}
				else {
					check_monitering(x, y, 0, tmp_map);
					check_monitering(x, y, 1, tmp_map);
				}
				break;
			case 3:
				if (d == 0) {
					check_monitering(x, y, 1, tmp_map);
					check_monitering(x, y, 2, tmp_map);
				}
				else {
					check_monitering(x, y, 0, tmp_map);
					check_monitering(x, y, 3, tmp_map);
				}
				break;
			case 4:
				if (d == 0) {
					check_monitering(x, y, 0, tmp_map);
					check_monitering(x, y, 2, tmp_map);
					check_monitering(x, y, 3, tmp_map);
				}
				else {
					check_monitering(x, y, 1, tmp_map);
					check_monitering(x, y, 2, tmp_map);
					check_monitering(x, y, 3, tmp_map);
				}
				break;
			}
		}
		//print_map(tmp_map);
		int val = check_noview(tmp_map);
		if (ans > val) {
			ans = val;
		}
		return;
	}
	int size = cameras.size();
	for (int i = 0; i < size; i++) {
		int x = cameras[i].x, y = cameras[i].y;
		cout << x << "," << y << "\n";
		switch (cameras[i].s) {
		case 1:
			for (int z = 0; z < 4; z++) {
				if (visited[x][y][z]) continue;
				visited[x][y][z] = true;
				cameras[i].d = z;
				solve(cnt + 1);
				visited[x][y][z] = false;
			}
			break;
		case 2:
			for (int z = 0; z < 2; z++) {
				if (visited[x][y][z]) continue;
				visited[x][y][z] = true;
				cameras[i].d = z;
				solve(cnt + 1);
				visited[x][y][z] = false;
			}
			break;
		case 3:
			for (int z = 0; z < 2; z++) {
				if (visited[x][y][z]) continue;
				visited[x][y][z] = true;
				cameras[i].d = z;
				solve(cnt + 1);
				visited[x][y][z] = false;
			}
			break;
		case 4:
			for (int z = 0; z < 2; z++) {
				if (visited[x][y][z]) continue;
				visited[x][y][z] = true;
				cameras[i].d = z;
				solve(cnt + 1);
				visited[x][y][z] = false;
			}
			break;
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
			if (map[i][j] != 0 && map[i][j] != 6 && map[i][j] != 5) {
				total++;
				cameras.push_back(pos(i, j, 0, map[i][j]));
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 5) {
				for (int z = 0; z < 4; z++) {
					//cout << i << "," << j << "," << z << "\n";
					check_monitering(i, j, z, map);
				}
			}
		}
	}
	//print_map(map);
	//cout << total << "\n";
	solve(0);
	cout << ans << "\n";
	return 0;
}