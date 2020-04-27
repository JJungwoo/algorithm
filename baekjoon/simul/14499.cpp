/*
[boj] 14499. 주사위 굴리기
(r,c) = (x,y);
지도의 각 칸에는 정수가 하나씩 쓰여져 있다. 주사위를 굴렸을 때, 
이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다. 
0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 
칸에 쓰여 있는 수는 0이 된다.
주사위를 놓은 곳의 좌표와 이동시키는 명령이 주어졌을 때, 
주사위가 이동했을 때 마다 상단에 쓰여 있는 값을 구하는 프로그램을 작성하시오.
만약 바깥으로 이동시키려고 하는 경우에는 해당 명령을 무시해야 하며, 출력도 하면 안 된다.
*/
#include <iostream>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, m, x, y, k;
int map[20][20], dirs[1001];
int dir[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };	// 동 서 북 남
int dice[6][2];	// 주사위 윗면 동 서 북 남 밑변
void solve()
{
	int cur = 0, next = 1;
	for (int i = 0; i < k; i++) {
		int d = dirs[i] - 1;
		int mx = x + dir[d][0], my = y + dir[d][1];
		if (mx < 0 || my < 0 || mx >= n || my >= m) continue;
		if (map[mx][my] == 0) {
			map[mx][my] = dice[dirs[i]][cur];
		}
		else {		// dice[dirs[i]] 가는 방향에서 밑면으로 바뀜
			dice[dirs[i]][cur] = map[mx][my];
			map[mx][my] = 0;
		}
		dice[5][next] = dice[dirs[i]][cur];	// 밑면

		// 동 <-> 서 , 0 <-> 1
		// 북 <-> 남 , 2 <-> 3
		dice[dirs[i]][next] = dice[0][cur];	// 현재 윗면이 가는 방향으로 

		// 윗면은 가는 방향의 반대면의 값
		if (d == 0 || d == 1) {
			int vd = ((d == 0) ? 2 : 1);
			// 0이면 동 <-> 서(dice에서는 2) 반대도 똑같이
			dice[0][next] = dice[vd][cur];
			// 가는 방향의 반대면은 현재 아래면을 가는 방향의 반대면에 추가
			dice[vd][next] = dice[5][cur];
			// 양옆면은 변화없음
			dice[3][next] = dice[3][cur];
			dice[4][next] = dice[4][cur];
		}
		else if (d == 2 || d == 3) {
			int vd = ((d == 2) ? 4 : 3);
			dice[0][next] = dice[vd][cur];
			dice[vd][next] = dice[5][cur];
			dice[1][next] = dice[1][cur];
			dice[2][next] = dice[2][cur];
		}

		// 윗면 출력
		cout << dice[0][next] << "\n";

		// 상태 변환
		next = cur;
		cur = (cur + 1) % 2;
		x = mx, y = my;
	}
}
int main()
{
	io;
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> dirs[i];
	}
	solve();
	return 0;
}