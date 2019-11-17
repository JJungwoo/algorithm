/*
BOJ 13460 ±∏ΩΩ ≈ª√‚ 2
https://www.acmicpc.net/problem/13460
*/
/*
#include <cstdio>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

char map[10][10];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
bool check[10][10][10][10];

struct location {
	int r_x, r_y, b_x, b_y, tcnt;
};

queue<location> ltq;

void move(int &x, int &y, int &cnt, int dx, int dy) {
	while (map[y + dy][x + dx] != '#' && map[y][x] != 'O') {
		x += dx;
		y += dy;
		cnt += 1;
	}
}

int bfs() {
	while (!ltq.empty()) {
		location tmp_lt = ltq.front();
		ltq.pop();
		tmp_lt.tcnt++;
		if (tmp_lt.tcnt > 10) 
			return -1;
		for (int i = 0; i < 4; i++) {
			location move_lt = tmp_lt;
			int rc = 0, bc = 0;
			move(move_lt.r_x, move_lt.r_y, rc, dx[i], dy[i]);
			move(move_lt.b_x, move_lt.b_y, bc, dx[i], dy[i]);
			if (map[move_lt.b_y][move_lt.b_x] == 'O') continue;
			if (map[move_lt.r_y][move_lt.r_x] == 'O') return move_lt.tcnt;
			if (move_lt.r_x == move_lt.b_x && move_lt.r_y == move_lt.b_y) {
				if (rc > bc) {
					move_lt.r_x -= dx[i];
					move_lt.r_y -= dy[i];
				}
				else {
					move_lt.b_x -= dx[i];
					move_lt.b_y -= dy[i];
				}
			}
			if (check[move_lt.r_y][move_lt.r_x][move_lt.b_y][move_lt.b_x]) continue;
			check[move_lt.r_y][move_lt.r_x][move_lt.b_y][move_lt.b_x] = true;
			ltq.push(move_lt);
		}
	}
	return -1;
}

int main()
{
	int n, m;
	location lt;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1s", &map[i][j]);
			if (map[i][j] == 'R') {
				lt.r_x = j;
				lt.r_y = i;
			}
			else if (map[i][j] == 'B') {
				lt.b_x = j;
				lt.b_y = i;
			}
		}
	}
	lt.tcnt = 0;
	ltq.push(lt);
	printf("%d\n",bfs());

	return 0;
}
*/