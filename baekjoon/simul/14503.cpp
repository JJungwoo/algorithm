/*
[boj] 14503. 로봇 청소기
1. 현재 위치를 청소한다.
2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
	a. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 
	1번부터 진행한다.
	b. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
	c. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 
	2번으로 돌아간다.
	d. 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 
	작동을 멈춘다.
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define CLEAN 2
#define BACK 3
int n, m, ans;
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int map[50][50];
struct robot{
	int x, y, d, cnt;
};
robot my;
void solve()
{
	while (1) {
		int x = my.x, y = my.y;
		if (map[x][y] == 0) {
			map[x][y] = CLEAN;
			my.cnt += 1;
		}
		
		bool check = false;
		int d = my.d;
		for(int i=0;i<4;i++) {
			d = (d - 1) == -1 ? d = 3 : d = (d - 1);
			int nx = x + dir[d][0], ny = y + dir[d][1];
			if (map[nx][ny] == 1) continue;
			if (map[nx][ny] == 0) {
				my.d = d;
				check = true;
				break;
			}
		}
		
		if (!check) {
			int nx = x - dir[my.d][0], ny = y - dir[my.d][1];
			if (map[nx][ny] == CLEAN) {
				map[nx][ny] == BACK;
				my.x = nx, my.y = ny;
			}else if(map[nx][ny] == BACK || map[nx][ny] == 1){
				break;
			}
		}
		else {
			my.x += dir[my.d][0], my.y += dir[my.d][1];
		}
	}
}
int main()
{
	io;
	cin >> n >> m;
	cin >> my.x >> my.y >> my.d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	cout << my.cnt << "\n";
	return 0;
}