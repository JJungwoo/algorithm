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
/*
#include <iostream>
#include <vector>

#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int a, b, n, m;
int dir[4][2] = { {-1,0},{0,1}, {1,0},{0,-1} };	// 시계방향 +1, 반시계방향 -1
struct robot{
	int x, y, d;
	int num;
};
struct command {
	int t, l;
	char cmd;
};
vector<robot> rlist;
vector<command> clist;	//cmd list
robot map[100][100];
void solve() {
	int size = clist.size();
	for (int i = 0; i < size; i++) {
		int target = clist[i].t;
		switch (clist[i].cmd) {
		case 'L':	// 왼쪽 90, -1
			int tmp = rlist[target].d;
			for (int j = 0; j < clist[i].l; j++)
				tmp = tmp - 1 == 0 ? 3 : tmp - 1;
			break;
		case 'R':	// 오른쪽 90, +1
			rlist[target].d = (rlist[target].d + clist[i].l) % 4;
			break;
		case 'F':	// 앞으로 한칸
			for (int j = 0; j < clist[i].l; j++) {
				rlist[target].x += dir[];
			}
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
		map[x][y].d = d;
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