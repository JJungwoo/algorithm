/*
[BOJ] 12100. 2048(Easy)
https://www.acmicpc.net/problem/12100

#include <cstdio>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

int map[20][20];
int n;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void move(int x, int y, int dx, int dy) {
	if (y + dy > n || y + dy < 0 || x + dx > n || x + dx < 0)
		return;
	while (map[y + dy][x + dx] == 0) {
		x += dx;
		y += dy;
	}
	map[y+dy][x+dx] += map[y][x];
	map[y][x] = 0;
}

int bruto_force(){
	for (int t = 0; t < 5; t++) {
		for (int i = 0; i < 4; i++) {
			for (int y = 0; y < n; y++) {
				for (int x = 0; x < n; x++) {
					move(x, y, dx[i], dy[i]);
				}
			}
		}
	}
}

int main()
{
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	printf("%d\n", bruto_force());
	
	return 0;
}
*/