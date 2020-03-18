/*
[boj] 17143. 낚시왕
*/

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
