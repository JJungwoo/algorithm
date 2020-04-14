/*
[boj] 2174. �κ� �ùķ��̼�
L: �κ��� ���ϰ� �ִ� ������ �������� �������� 90�� ȸ���Ѵ�.
R: �κ��� ���ϰ� �ִ� ������ �������� ���������� 90�� ȸ���Ѵ�.
F: �κ��� ���ϰ� �ִ� ������ �������� ������ �� ĭ �����δ�.

Robot X crashes into the wall: X�� �κ��� ���� �浹�ϴ� ����̴�. 
��, �־��� ���� ������ ����� ��찡 �ȴ�.
Robot X crashes into robot Y: X�� �κ��� �����̴ٰ� Y�� �κ��� �浹�ϴ� ����̴�.
��� �κ��� ���������� �����δ�.
*/

#include <iostream>
#include <vector>

#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int a, b, n, m;
int dir[4][2] = { {-1,0},{0,1}, {1,0},{0,-1} };	// �ð���� +1, �ݽð���� -1
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
		case 'L':	// ���� 90, -1
			rlist[target].d = (rlist[target].d + clist[i].l + 2) % 4;
			break;
		case 'R':	// ������ 90, +1
			rlist[target].d = (rlist[target].d + clist[i].l) % 4;
			break;
		case 'F':	// ������ ��ĭ
			for (int j = 0; j < clist[i].l; j++) {
				int x = rlist[target].x, y = rlist[target].y;
				int d = rlist[target].d;
				if(map[x + dir[d][0]][y + dir[d][1]].num != 0){
					cout<<"Robot "<<target<<" crashes into robot "<<map[x + dir[d][0]][y + dir[d][1]].num<<"\n";
					return;
				}else if(x + dir[d][0] < 0 || y + dir[d][1] < 0 || 
						x + dir[d][0] >= b || y + dir[d][1] >= a)
				{	
					cout<<x + dir[d][0]<<","<<y + dir[d][1]<<"\n";
					cout<<"Robot "<<target<<" crashes into the wall\n";
					return;
				}else{
					map[x + dir[d][0]][y + dir[d][1]].num = map[x][y].num;
					map[x + dir[d][0]][y + dir[d][1]].d = map[x][y].d;
					rlist[target].x += dir[d][0];
					rlist[target].y += dir[d][1];
					map[x][y].num = 0;
					map[x][y].d = 0;
				}
			}
			break;
		}
	}
	cout<<"OK\n";
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
		x--, y--;
		int td = (d == 'N' ? 0 : d == 'E' ? 1 : d == 'S' ? 2 : d == 'W' ? 3 : -1);
		rlist.push_back({ x,y,td,i+1 });
		map[x][y].d = d;
		map[x][y].num = i+1;
	}
	for (int i = 0; i < m; i++) {
		// Ÿ��, ����, �ݺ� Ƚ��
		int target, loop;
		char cmd;
		cin >> target >> cmd >> loop;
		target--;
		clist.push_back({ target,loop,cmd });
	}
	solve();
	return 0;
}

