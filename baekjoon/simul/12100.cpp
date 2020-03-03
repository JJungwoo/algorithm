/*
[boj] 12100. 2048 (Easy)
10
0 0 64 32 32 0 0 0 0 0
0 32 32 64 0 0 0 0 0 0
0 0 128 0 0 0 0 0 0 0 
64 64 128 0 0 0 0 0 0 0
0 0 64 32 32 0 0 0 0 0
0 32 32 64 0 0 0 0 0 0
0 0 128 0 0 0 0 0 0 0 
64 64 128 0 0 0 0 0 0 0
128 32 2 4 0 0 0 0 0 0
0 0 128 0 0 0 0 0 0 0
답 : 1024
output: 512
[#2]
7
2 2 2 2 2 2 2
2 0 2 2 2 2 2
2 0 2 2 2 2 2
2 0 2 2 2 2 2
2 2 2 0 2 2 2 
2 2 2 2 2 2 0
2 2 2 2 2 2 0
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, ans;
int map[21][21], tmp_map[21][21];
vector<int> dir_v;
void print_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << tmp_map[i][j] << " ";
		}
		cout << "\n";
	}
}
void copy_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp_map[i][j] = map[i][j];
		}
	}
}
void move_map() {
	for (int i = 0; i < dir_v.size(); i++) {
		//bool change[430] = { 0, };	// i*n+j (n*n+n)
		bool change[21][21];
		memset(change, 0, sizeof(change));
		int dir = dir_v[i];
		switch (dir) {		// 상, 하, 좌, 우
		case 0:
			for (int x = 1; x < n; x++) {
				for (int y = 0; y < n; y++) {
					bool check = 0;
					int z = 1;
					while (tmp_map[x - z][y] == 0) { // x:1,y:2,z:1
						check = 1;
						//cout << "0 "<<tmp_map[x-z][y]<<" x:"<<x<<", y:"<<y<<", z:"<<z<<"\n";
						if(x - z >= 0) z++;
						else break;
					}
					z--;
					if(check) swap(tmp_map[x][y], tmp_map[x - z][y]);
					if (tmp_map[x][y] == tmp_map[x - 1][y] && !change[x - 1][y]) {
						tmp_map[x - 1][y] += tmp_map[x][y];
						tmp_map[x][y] = 0;
						change[x - 1][y] = true;
					}
				}
			}
			break;
		case 1:
			for (int x = n - 1; x >= 0; x--) {
				for (int y = 0; y < n; y++) {
					bool check = 0;
					int z = 1;
					while (tmp_map[x + z][y] == 0) {
						check = 1;
						if (x + z < n) z++;
						else break;
					}
					z--;
					if (check) swap(tmp_map[x][y], tmp_map[x + z][y]);
					if (tmp_map[x][y] == tmp_map[x + 1][y] && !change[x + 1][y]) {
						tmp_map[x + 1][y] += tmp_map[x][y];
						tmp_map[x][y] = 0;
						change[x + 1][y] = true;
					}
				}
			}
			break;
		case 2:		// 좌
			for (int y = 1; y < n; y++) {
				for (int x = 0; x < n; x++) {
					bool check = 0;
					int z = 1;
					while (tmp_map[x][y - z] == 0) {
						check = 1;
						if (y - z >= 0) z++;
						else break;
					}
					z--;
					if (check) swap(tmp_map[x][y], tmp_map[x][y - z]);
					if (tmp_map[x][y] == tmp_map[x][y - 1] && !change[x][y - 1]) {
						tmp_map[x][y - 1] += tmp_map[x][y];
						tmp_map[x][y] = 0;
						change[x][y - 1] = true;
					}
				}
			}
			break;
		case 3:		// 우
			for (int y = n - 1; y >= 0; y--) {
				for (int x = 0; x < n; x++) {
					bool check = 0;
					int z = 1;
					while (tmp_map[x][y + z] == 0) {
						check = 1;
						if (y + z < n) z++;
						else break;
					}
					z--;
					if (check) swap(tmp_map[x][y], tmp_map[x][y + z]);
					if (tmp_map[x][y] == tmp_map[x][y + 1] && !change[x][y + 1]) {
						tmp_map[x][y + 1] += tmp_map[x][y];
						tmp_map[x][y] = 0;
						change[x][y + 1] = true;
					}
				}
			}
			break;
		}
	}
}
void calc_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(ans, tmp_map[i][j]);
		}
	}
}
void solve(int cnt) {
	if (cnt == 5) {
		copy_map();
		move_map();
		calc_map();
		//print_map();
		return;
	}
	for (int i = 0; i < 4; i++) {
		dir_v.push_back(i);
		solve(cnt + 1);
		dir_v.pop_back();
	}
}
int main()
{
    io;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	solve(0);
	cout << ans << "\n";
	return 0;
}