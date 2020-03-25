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
�� : 1024
output: 512
[#2]
7
2 0 2 2 2 2 2
2 0 2 2 2 2 2
2 0 2 2 2 2 2
2 0 2 2 2 2 2
2 2 2 0 2 2 2
2 2 2 2 2 2 0
2 2 2 2 2 2 0
32

7
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 4 8
0 0 0 0 0 8 16
0 0 0 0 0 8 16
0 0 0 0 8 16 2

���� ������ �������

0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 4 8
0 0 0 0 0 16 32
0 0 0 0 8 16 2

�� ����������

0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 8
0 0 0 0 0 4 32
0 0 0 0 8 32 2

�� �ڵ�

7
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 4 8
0 0 0 0 0 8 16
0 0 0 0 0 8 16
0 0 0 0 8 16 2

0 0 0 0 0 0 0
0 0 0 0 8 4 8
0 0 0 0 0 16 32
0 0 0 0 0 16 2
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0

0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 4 8
0 0 0 0 0 16 32
0 0 0 0 8 16 2

0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
8 0 0 0 0 0 4
16 0 0 0 0 0 8
16 0 0 0 0 0 8
16 0 0 0 0 8 2

0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 4 8
0 0 0 0 0 8 16
0 0 0 0 0 8 16
0 0 0 0 8 16 2
32

*/
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
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
		switch (dir) {		// ��, ��, ��, ��
		case 0:
			for (int x = 1; x < n; x++) {
				for (int y = 0; y < n; y++) {
					bool check = 0;
					int z = 1;
					while (tmp_map[x - z][y] == 0) { // x:1,y:2,z:1
						check = 1;
						//cout << "0 "<<tmp_map[x-z][y]<<" x:"<<x<<", y:"<<y<<", z:"<<z<<"\n";
						if(x - z > 0) z++;
						else break;
					}
					z--;
					if(check) swap(tmp_map[x][y], tmp_map[x - z][y]);
					int move = x - z;
					if (tmp_map[move][y] == tmp_map[move - 1][y] && !change[move - 1][y]) {
						tmp_map[move - 1][y] += tmp_map[move][y];
						tmp_map[move][y] = 0;
						change[move - 1][y] = true;
					}
				}
			}
			break;
		case 1:
			for (int x = n - 2; x >= 0; x--) {
				for (int y = 0; y < n; y++) {
					bool check = 0;
					int z = 1;
					while (tmp_map[x + z][y] == 0) {
						check = 1;
						if (x + z < n - 1) z++;
						else break;
					}
					z--;
					if (check) swap(tmp_map[x][y], tmp_map[x + z][y]);
					int move = x + z;
					if (tmp_map[move][y] == tmp_map[move + 1][y] && !change[move + 1][y]) {
						tmp_map[move + 1][y] += tmp_map[move][y];
						tmp_map[move][y] = 0;
						change[move + 1][y] = true;
					}
				}
			}
			break;
		case 2:		// ��
			for (int x = 0; x < n; x++) {
				for (int y = 1; y < n; y++) {
					bool check = 0;
					int z = 1;
					//while (tmp_map[x][y - z] == 0) {
					if (tmp_map[x][y] != 0) {
						while (1) {
							if (tmp_map[x][y - z] == 0 && y - z > 0) {
								z++;
								check = 1;
							}
							else break;
						}
						if (check) swap(tmp_map[x][y], tmp_map[x][y - z]);
						int move = y - z;
						if (tmp_map[x][move] == tmp_map[x][move - 1] && !change[x][move - 1]) {
							tmp_map[x][move - 1] += tmp_map[x][move];
							tmp_map[x][move] = 0;
							change[x][move - 1] = true;
						}
					}
				}
			}
			break;
		case 3:		// ��
			for (int x = 0; x < n; x++) {
				for (int y = n - 2; y >= 0; y--) {
					bool check = 0;
					int z = 1;
					while (tmp_map[x][y + z] == 0) {
						check = 1;
						if (y + z < n - 1) z++;
						else break;
					}
					z--;
					if (check) swap(tmp_map[x][y], tmp_map[x][y + z]);
					int move = y + z;
					if (tmp_map[x][move] == tmp_map[x][move + 1] && !change[x][move + 1]) {
						tmp_map[x][move + 1] += tmp_map[x][move];
						tmp_map[x][move] = 0;
						change[x][move + 1] = true;
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
	if (cnt == 1) {
		copy_map();
		move_map();
		calc_map();
		cout << "\n";
		print_map();
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
*/


#include <iostream>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int n, ans;
int map[20][20];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
vector<int> moving;

inline bool gocheck(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n) return false;
	return true;
}

void copy_map(int tmp_map[20][20]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp_map[i][j] = map[i][j];
		}
	}
}

void print_map(int tmp_map[20][20]) {
	cout << "print_map\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << tmp_map[i][j] << " ";
		}
		cout << "\n";
	}
}

void move(int x, int y, int d) {
	int mx = x + dir[d][0], my = y + dir[d][1];
	while (gocheck(mx,my)) {
		if (map[mx][my] != 0) {
			if (map[mx - dir[d][0]][my - dir[d][1]] == map[mx][my]) {
				map[mx][my] += map[mx - dir[d][0]][my - dir[d][1]];
				map[my - dir[d][0]][my - dir[d][1]] = 0;
				break;
			}
			else {
				break;
			}
		}
		mx += dir[d][0];
		my += dir[d][0];
	}
	mx -= dir[d][0];
	my -= dir[d][1];
}

void move_map(int mdir) {
	switch (mdir) {
	case 0:	// ��
		for (int i = 0; i < n; i++) {
			move(n - 1, i, mdir);
		}
		break;
	case 1:	// ��
		for (int i = 0; i < n; i++) {
			move(0, i, mdir);
		}
		break;
	case 2:	// ��
		for (int i = 0; i < n; i++) {
			move(i, n - 1, mdir);
		}
		break;
	case 3:	// ��
		for (int i = 0; i < n; i++) {
			move(i, 0, mdir);
		}
		break;
	}
}

void solve(int cur, int cnt) {
	if (cnt == 5) {
		int tmp_map[20][20];
		copy_map(tmp_map);
		print_map(map);
		
		int size = moving.size();	// 0(��), 1(��), 2(��), 3(��)
		
		for (int i = 0; i < size; i++) {
			cout << size << ","<<i<<"\n";
			for (int j = 0; j < 4; j++) {
				move_map(j);
			}
		}
		//print_map(tmp_map);
		int max = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (max < tmp_map[i][j]) {
					max = tmp_map[i][j];
				}
			}
		}
		if (ans < max) {
			ans = max;
		}
		return;
	}

	for (int i = cur; i < 4; i++) {
		moving.push_back(i);
		solve(i, cnt + 1);
		moving.pop_back();
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
	solve(0, 0);
	cout << ans << "\n";
	return 0;
}