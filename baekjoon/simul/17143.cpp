/*
[boj] 17143. 낚시왕
*/
#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int r, c, m, ans;
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

struct shark {
	int r, c, s, d, z;	// x, y, 속력, 방향, 크기
	//shark(int _r, int _c, int _s, int _d, int _z) :r(_r), c(_c), s(_s), d(_d), z(_z) {};
};

shark map[100][100][2];

void print_map(int state) {
	cout << "print_map(" << state << " )\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[i][j][state].z << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void init_map(int state) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			map[i][j][state].z = 0;
		}
	}
}

void solve() {		// 낚시왕 이동, 자신의 열의 상어 잡기, 상어 이동
	int next = 1, cur = 0;
	for (int i = 0; i < c; i++) {	// 낚시왕 이동
		for (int j = 0; j < r; j++) {
			if (map[j][i][cur].z != 0) {
				ans += map[j][i][cur].z;
				map[j][i][cur].z = 0;
				map[j][i][cur].s = 0;
				map[j][i][cur].d = 0;
				break;
			}
		}

		// 상어 이동
		for (int x = 0; x < r; x++) {
			for (int y = 0; y < c; y++) {
				if (map[x][y][cur].z != 0) {
					//cout << "cur" << x << ":" << y << "="<<map[x][y][cur].z<<"\n";
					int d = map[x][y][cur].d;	// 상, 하, 좌, 우
					//cout << d << "\n";
					if (d < 2) {		// 상, 하
						int s = map[x][y][cur].s % ((r - 1) * 2);
						int mx = x;
						while (s--) {
							if (mx == 0 && d == 0) d = 1;	// 상
							if (mx == r - 1 && d == 1) d = 0;
							mx += dir[d][0];
						}
						//cout << "cur" << x << ":" << y << "=" << map[x][y][cur].z << "\n";
						//cout << "next" << mx << ":" << y << "=" << map[mx][y][next].z << "\n";
						if (map[mx][y][next].z != 0) {
							if (map[mx][y][next].z < map[x][y][cur].z) {
								map[mx][y][next].d = d;
								map[mx][y][next].s = map[x][y][cur].s;
								map[mx][y][next].z = map[x][y][cur].z;
							}
						}
						else {
							map[mx][y][next].d = d;
							map[mx][y][next].s = map[x][y][cur].s;
							map[mx][y][next].z = map[x][y][cur].z;
						}
					}
					else {		// 좌, 우
						int s = map[x][y][cur].s % ((c - 1) * 2);
						int my = y;
						while (s--) {
							if (my == 0 && d == 3) d = 2;	// 좌
							if (my == c - 1 && d == 2) d = 3;
							my += dir[d][1];
						}

						//cout << "cur" << x << ":" << y << "=" << map[x][y][cur].z << "\n";
						//cout << "next" << x << ":" << my << "=" << map[x][my][next].z << "\n";
						if (map[x][my][next].z != 0) {
							if (map[x][my][next].z < map[x][y][cur].z) {
								map[x][my][next].d = d;
								map[x][my][next].s = map[x][y][cur].s;
								map[x][my][next].z = map[x][y][cur].z;
							}
						}
						else {
							map[x][my][next].d = d;
							map[x][my][next].s = map[x][y][cur].s;
							map[x][my][next].z = map[x][y][cur].z;
						}
					}
				}
				map[x][y][cur] = { x, y ,0, 0, 0 };
			}
		}
		//init_map(cur);
		//print_map(next);

		next = cur;
		cur = (cur + 1) % 2;
	}
}

int main() {
	io;
	cin >> r >> c >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		a--, b--, d--;
		map[a][b][0].s = c;
		map[a][b][0].d = d;
		map[a][b][0].z = e;
	}

	solve();
	cout << ans << "\n";
	return 0;
}
/*
#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int r, c, m, ans;
struct shark {
	int s, d, z;
};
shark sharkArr[2][101][101];

void hunt_shark(int cur, int y) {
	int x = 0;
	while (sharkArr[cur][x][y].z == 0) {
		x++;
	}
	ans += sharkArr[cur][x][y].z;
	sharkArr[cur][x][y].s = 0;
	sharkArr[cur][x][y].d = 0;
	sharkArr[cur][x][y].z = 0;
}

void move_shark(int cur) {
	int next = (cur + 1) % 2;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (sharkArr[next][i][j].z) {
				sharkArr[next][i][j].s = 0;
				sharkArr[next][i][j].d = 0;
				sharkArr[next][i][j].z = 0;
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (sharkArr[cur][i][j].z != 0) {
				switch (sharkArr[cur][i][j].d) {
				case 1:	// 상 y--

					break;
				case 2:	// 하 y++
					break;
				case 3:	// 우 x++
					break;
				case 4:	// 좌 x--
					break;
				}
			}
		}
	}
}

void solve() {
	int cur = 0;
	for (int i = 0; i < c; i++) {	// 낚시왕의 이동
		hunt_shark(cur, i);
		move_shark(cur);
		cur = (cur + 1) % 2;
	}
}

int main()
{
	io;
	for (int i = 0; i < m; i++) {
		int x, y, s, d, z;
		cin >> x >> y >> s >> d >> z;
		x--;
		y--;
		sharkArr[0][x][y].s = s;
		sharkArr[0][x][y].d = d;
		sharkArr[0][x][y].z = z;
	}
	solve();
	cout << ans << "\n";
	return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int r, c, m, ans;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

struct shark {
	int x, y, s, d, z;	// 좌표(x,y), 속력(s), 방향(d), 크기(z)
	shark(int _x, int _y, int _s, int _d, int _z) :x(_x), y(_y), s(_s), d(_d), z(_z) {};
};

vector<shark> vs, new_vs;

bool compare(shark a, shark b) {
	return a.x < b.x;
}

void hunt_shark(int y, vector<shark> tmp) {
	int x = 0, size = tmp.size(), i;
	vector<shark>::iterator iter = tmp.begin();
	for (i = 0; i < size; i++) {
		if (tmp[i].y == y) {
			ans += tmp[i].z;
			break;
		}
	}
	tmp.erase(iter + i);
}

void move_shark(vector<shark> tmp) {
	int size = tmp.size();
	int map[101][101];
	memset(map, 0, sizeof(map));
	for (int i = 0; i < size; i++) {
		int mx = tmp[i].x;
		int my = tmp[i].y;
		if (map[mx][my] == 0) {
			map[mx][my] = tmp[i].z;
		}
		else if(map[mx][my] < tmp[i].z){

		}
	}
}

void eat_shark(vector<shark> tmp) {
	new_vs.clear();
	int size = tmp.size();
	for (int i = 0; i < size; i++) {
		if (tmp[i].z == 0) continue;	// 죽은 상어 무시
		new_vs.push_back(tmp[i]);		// 새로운 상어 리스트
	}
}

void print_sharks(vector<shark> tmp) {
	cout << "print_sharks\n";
	int size = tmp.size();
	int map[101][101];
	memset(map, 0, sizeof(map));
	for (int i = 0; i < size; i++) {
		map[tmp[i].x][tmp[i].y] = tmp[i].z;
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

void solve() {
	int ky = -1;
	vector<shark> tmp = vs;
	for (int i = 0; i < c; i++) {	// 오른쪽으로 이동
		vector<shark> tmp = new_vs;
		sort(tmp.begin(), tmp.end(), compare);
		hunt_shark(i, tmp);	// 가장 가까운 상어 사냥
		move_shark(tmp);
		eat_shark(tmp);
		print_sharks(tmp);
	}
}

int main()
{
	io;
	cin >> r >> c >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		vs.push_back(shark(a, b, c, d, e));
	}
	solve();
	cout << ans << "\n";

	return 0;
}
*/
/*
//iter, sort 테스트
struct shark {
	int x, y, s, d, z;	// 좌표(x,y), 속력(s), 방향(d), 크기(z)
	shark(int _x, int _y, int _s, int _d, int _z) :x(_x), y(_y), s(_s), d(_d), z(_z) {};
};

vector<shark> vs;

bool compare(shark a, shark b) {
	return a.x < b.x;
}

int x = 0, size = vs.size(), i;
vector<shark>::iterator iter = vs.begin();
sort(vs.begin(), vs.end(), compare);
cout << "\n";
for (i = 0; i < size; i++) {
	cout << vs[i].x << "," << vs[i].y << "," << vs[i].s << "," << vs[i].d << "," << vs[i].z << "\n";
}
vs.erase(iter + 0);
cout << "\n";
for (i = 0; i < vs.size(); i++) {
	cout << vs[i].x << "," << vs[i].y << "," << vs[i].s << "," << vs[i].d << "," << vs[i].z << "\n";
}
*/

