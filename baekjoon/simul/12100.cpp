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
╢Д : 1024
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

*/
#include <iostream>
#include <vector>
#include <cstring>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int n, ans;
int map[20][20];
vector<int> moving;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
bool change[20][20];

struct G2048 {
	void copy_map(int tmp[20][20]) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				tmp[i][j] = map[i][j];
			}
		}
	}

	void print_map(int tmp[20][20]) {
		cout << "print_map\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << tmp[i][j] << " ";
			}
			cout << "\n";
		}
	}

	int find_max(int tmp[20][20]) {
		int max = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (max < tmp[i][j]) {
					max = tmp[i][j];
				}
			}
		}
		return max;
	}

	void move(int x, int y, int d, int tmp[20][20]) {
		int mx = x, my = y;
		if (tmp[mx][my] == 0) return;
		while (1) {
			int gox = mx + dir[d][0], goy = my + dir[d][1];
			if (gox < 0 || goy < 0 || gox >= n || goy >= n) break;
			else if (tmp[gox][goy] != 0) {
				if (tmp[mx][my] == tmp[gox][goy] && change[gox][goy] == false) {
					tmp[gox][goy] += tmp[mx][my];
					tmp[mx][my] = 0;
					change[gox][goy] = true;
					break;
				}
				else break;
			}
			else {
				swap(tmp[gox][goy], tmp[mx][my]);
			}

			//print_map(tmp);
			mx += dir[d][0], my += dir[d][1];
		}
	}

	void move_board(int tmp[20][20]) {
		int size = moving.size();
		for (int d = 0; d < size; d++) {
			memset(change, 0, sizeof(change));
			switch (moving[d]) {
			case 0:	// ╩С, го, аб, ©Л
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						move(i, j, moving[d], tmp);
					}
				}
				break;
			case 1:
				for (int i = n-1; i >= 0; i--) {
					for (int j = 0; j < n; j++) {
						move(i, j, moving[d], tmp);
					}
				}
				break;
			case 2:
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						move(i, j, moving[d], tmp);
					}
				}
				break;
			case 3:
				for (int i = 0; i < n; i++) {
					for (int j = n - 1; j >= 0; j--) {
						move(i, j, moving[d], tmp);
					}
				}
				break;
			}
		}
		//print_map(tmp);
	}
};
G2048 game;

void solve(int cnt) {
	if (cnt == 5) {
		int tmp_map[20][20];
		game.copy_map(tmp_map);
		game.move_board(tmp_map);
		int find_ans = game.find_max(tmp_map);
		//game.print_map(tmp_map);
		if (ans < find_ans) {
			ans = find_ans;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		moving.push_back(i);
		solve(cnt + 1);
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
	solve(0);
	cout << ans << "\n";
	return 0;
}








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
		switch (dir) {		// ╩С, го, аб, ©Л
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
		case 2:		// аб
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
		case 3:		// ©Л
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

/*
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

void move(int x, int y, int d, int tmap[20][20]) {
	int mx = x, my = y;
	while (1) {
		//cout<<tmap[mx][my]<<":"<< "mx:" << mx << ",my:" << my << "\n";

		int gox = mx + dir[d][0], goy = my + dir[d][1];
		cout << gox << "," << goy << " : " << mx << "," << my << "\n";
		if (gocheck(gox, goy)) {
			if (tmap[mx][my] == tmap[gox][goy] && tmap[gox][goy] != 0) {
				tmap[gox][goy] += tmap[mx][my];
				tmap[mx][my] = 0;
				cout <<"d:"<<d<<","<< tmap[gox][goy] << ":" << "x:" << mx << ",y:" << my << "\n";
			}
			else if(tmap[gox][goy] == 0){
				swap(tmap[mx][my], tmap[gox][goy]);
			}

			mx += dir[d][0];
			my += dir[d][1];
		}
		else break;
		print_map(tmap);
		
	}
}

void move_map(int mdir, int tmap[20][20]) {
	switch (mdir) {
	case 0:	// ╩С
		for (int i = 0; i < n; i++) {
			move(0, i, mdir, tmap);
		}
		break;
	case 1:	// го
		for (int i = 0; i < n; i++) {
			move(n - 1, i, mdir, tmap);
		}
		break;
	case 2:	// аб
		for (int i = 0; i < n; i++) {
			move(i, 0, mdir, tmap);
		}
		break;
	case 3:	// ©Л
		for (int i = 0; i < n; i++) {
			move(i, n - 1, mdir, tmap);
		}
		break;
	}
}

void solve(int cur, int cnt) {
	if (cnt == 5) {
		int tmp_map[20][20];
		copy_map(tmp_map);
		
		int size = moving.size();	// 0(╩С), 1(го), 2(аб), 3(©Л)
		
		for (int i = 0; i < size; i++) {
			cout << size << ","<<i<<"\n";
			for (int j = 0; j < 4; j++) {
				move_map(j, tmp_map);
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
		print_map(tmp_map);
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
*/