/*
[boj] 2174. 로봇 시뮬레이션
L: 로봇이 향하고 있는 방향을 기준으로 왼쪽으로 90도 회전한다.
R: 로봇이 향하고 있는 방향을 기준으로 오른쪽으로 90도 회전한다.
F: 로봇이 향하고 있는 방향을 기준으로 앞으로 한 칸 움직인다.

Robot X crashes into the wall: X번 로봇이 벽에 충돌하는 경우이다. 
즉, 주어진 땅의 밖으로 벗어나는 경우가 된다.
Robot X crashes into robot Y: X번 로봇이 움직이다가 Y번 로봇에 충돌하는 경우이다.
모든 로봇은 순차적으로 움직인다.
*/
#include <iostream>
#include <vector>

#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int a, b, n, m;
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
struct robot {
	int num, d;
};
struct cmd {
	int num, loop;
	char kind;
};
robot map[101][101];
pair<int, int> rbt[101];
vector<cmd> v;
void solve() {
	int cmd_size = v.size();
	for (int i = 0; i < cmd_size; i++) {
		int x = rbt[v[i].num].first, y = rbt[v[i].num].second;
		switch (v[i].kind) {
		case 'L':
			for (int j = 0; j < v[i].loop % 4; j++) {
				map[x][y].d--;
				if (map[x][y].d < 0) map[x][y].d = 3;
			}
			break;
		case 'R':
			map[x][y].d = (map[x][y].d + v[i].loop) % 4;
			break;
		case 'F':
			for (int j = 0; j < v[i].loop; j++) {
				int d = map[x][y].d;
				int mx = x + dir[d][0], my = y + dir[d][1];
				if (mx < 1 || my < 1 || mx > b || my > a) {		// 벽과 충돌
					cout << "Robot " << map[x][y].num << " crashes into the wall\n";
					return;
				}
				else if (map[mx][my].num != 0) {	// 다른 로봇 충돌
					cout << "Robot "<<map[x][y].num<<" crashes into robot "<<map[mx][my].num<< "\n";
					return;
				}
				rbt[map[x][y].num].first = mx;
				rbt[map[x][y].num].second = my;
				map[mx][my] = map[x][y];
				map[x][y].d = 0;
				map[x][y].num = 0;
				x = mx;
				y = my;
			}
			break;
		}
	}
	cout << "OK\n";
}
int main()
{
	io;
	cin >> a >> b;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x, y; 
		char d;
		cin >> y >> x >> d;
		x = (b - x) + 1;
		map[x][y].num = i+1;
		map[x][y].d = (d == 'N' ? d = 0 : d == 'E' ? d = 1 : d == 'S' ? d = 2 : d == 'W' ? d = 3 : d = -1);
		rbt[i + 1].first = x, rbt[i + 1].second = y;
	}
	for (int i = 0; i < m; i++) {
		int num, loop;
		char command;
		cin >> num >> command >> loop;
		v.push_back({ num, loop, command });
	}
	solve();
	return 0;
}

/*
#include <iostream>
#include <vector>

#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int a, b, n, m;
int dir[4][2] = { {-1,0},{0,1}, {1,0},{0,-1} };	// 시계방향 +1, 반시계방향 -1
struct robot {
	int x, y, dir, num;	// 0, 1, 2, 3 N E S W 상, 우, 하, 좌
};
struct cmd {
	int target, loop;
	char kind;
};
vector<robot> rlist;
vector<cmd> clist;
robot map[100][100];

void solve() {
	int size = clist.size();
	for (int i = 0; i < size; i++) {
		int target = clist[i].target;
		char cmd = clist[i].kind;
		switch (cmd) {
		case 'L':	// 반시계방향
			int res = (rlist[target].dir + clist[i].loop) % 6;
			if(res )
			rlist[target].dir = (rlist[target].dir + clist[i].loop) % 6;
			break;
		case 'R':	// 시계방향
			rlist[target].dir = (rlist[target].dir + clist[i].loop) % 4;
			break;
		case 'F':
			break;
		}
	}
}

int main()
{
	io;
	cin >> a >> b;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x, y;
		char d;
		cin >> x >> y >> d;
		int td = (d == 'N' ? 0 : d == 'E' ? 1 : d == 'S' ? 2 : d == 'W' ? 3 : -1);
		rlist.push_back({ x,y,td,i });
		map[x][y].dir = td;
		map[x][y].num = i;
	}
	for (int i = 0; i < m; i++) {
		// 타겟, 종류, 반복 횟수
		int target, loop;
		char cmd;
		cin >> target >> cmd >> loop;
		target--;
		clist.push_back({ target,loop,cmd });
	}
	solve();
	return 0;
}
*/