/*
[boj] 19236. 청소년 상어
https://www.acmicpc.net/problem/19236
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define swap(A, B) {int tmp; tmp = A; A = B; B = tmp;}
int answer;
int dir[8][2] = { {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1} }; // 반시계 방향

inline void copy_map(pair<int, int> src[4][4], pair<int, int> dest[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			dest[i][j].first = src[i][j].first;
			dest[i][j].second = src[i][j].second;
		}
	}
}

void solve(int x, int y, int sum, int d, vector<pair<int, int> > tfish, pair<int, int> map[4][4]) {
	if (sum > answer)
		answer = sum;
	for (int i = 1; i <= 16; i++) {
		if (map[tfish[i].first][tfish[i].second].first != i || tfish[i].first == -1 || tfish[i].second == -1) {
			continue;
		}
		bool move = true;
		int curd = map[tfish[i].first][tfish[i].second].second;
		int tmp_d = curd;
		int fmx = tfish[i].first + dir[curd][0], fmy = tfish[i].second + dir[curd][1];
		while (true) {
			if (fmx >= 0 && fmy >= 0 && fmx < 4 && fmy < 4 && !(fmx == x && fmy == y)) break;
			curd = (curd + 1) % 8;
			if (curd == map[tfish[i].first][tfish[i].second].second) {
				move = false;
				break;
			}
			fmx = tfish[i].first + dir[curd][0], fmy = tfish[i].second + dir[curd][1];
		}

		if (!move)
			continue;

		int tidx = map[fmx][fmy].first;
		map[tfish[i].first][tfish[i].second].second = curd;

		// 맵의 물고기 번호와 방향 스왑
		swap(map[tfish[i].first][tfish[i].second].first, map[fmx][fmy].first);
		swap(map[tfish[i].first][tfish[i].second].second, map[fmx][fmy].second);

		// 물고기 리스트의 위치 정보 변경
		if (tidx == -1) {
			tfish[i].first = fmx;
			tfish[i].second = fmy;
		}
		else {
			swap(tfish[i].first, tfish[tidx].first);
			swap(tfish[i].second, tfish[tidx].second);
		}
	}

	for (int i = 1; i <= 3; i++) {
		int mx = x + (dir[d][0] * i), my = y + (dir[d][1] * i);
		if (mx < 0 || my < 0 || mx >= 4 || my >= 4) continue;
		if (map[mx][my].first == -1) continue;

		pair<int, int> tmap[4][4];
		copy_map(map, tmap);

		int td = tmap[mx][my].second;
		int tmp = sum + tmap[mx][my].first;

		tmap[mx][my].first = -1;
		tmap[mx][my].second = -1;

		solve(mx, my, tmp, td, tfish, tmap);

		tmap[mx][my].first = tmp - sum;
		tmap[mx][my].second = td;
	}
}
int main()
{
	int map[4][4], dir_map[4][4];
	vector<pair<int, int> > fish;
	pair<int, int> pmap[4][4];
	for (int i = 0; i < 4; i++) {
		int idx = 0;
		for (int j = 1; j <= 8; j++) {
			if (j % 2 != 0)
				cin >> map[i][idx];
			else {
				cin >> dir_map[i][idx];
				idx++;
			}
		}
	}

	fish.resize(17, { -1, -1 });
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			pmap[i][j].first = map[i][j];
			pmap[i][j].second = dir_map[i][j] - 1;
			if (i == 0 && j == 0) continue;
			fish[map[i][j]] = { i,j };
		}
	}

	pmap[0][0].first = -1;
	pmap[0][0].second = -1;
	solve(0, 0, map[0][0], dir_map[0][0] - 1, fish, pmap);
	cout << answer << "\n";
	return 0;
}