/*
[boj] 2234. 성곽
1. 성에 있는 방의 개수
2. 가장 넓은 방의 넓이
3. 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
*/

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
struct room {
	int x, y;
};
int n, m, ans1, ans2, ans3; 
int map[51][51], copymap[51][51];
int dir[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };
// 1 2 4 8 : 서 북 동 남
bool visited[51][51];

int bfs(int x, int y, int tmp_map[51][51])
{
	int result = 1;
	queue<room> q;
	q.push({ x, y });
	while (!q.empty()) {
		int dx = q.front().x, dy = q.front().y;
		q.pop();
		for (int i = 0, k = 1; i < 4; i++, k <<= 1) {
			int mx = dx + dir[i][0], my = dy + dir[i][1];
			if (mx < 0 || my < 0 || mx >= m || my >= n) continue;
			if (visited[mx][my]) continue;
			if (tmp_map[dx][dy] & k) continue;
			visited[mx][my] = true;
			q.push({ mx, my });
			result++;
		}
	}
	return result;
}
void copy_map() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			copymap[i][j] = map[i][j];
		}
	}
}
int main()
{
	io;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) continue;
			ans1++;
			visited[i][j] = true;
			int res = bfs(i, j, map);
			if (ans2 < res) {
				ans2 = res;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int z = 0, k = 1; z < 4; z++, k <<= 1) {
				memset(visited, 0, sizeof(visited));
				copy_map();
				if (copymap[i][j] & k) {
					copymap[i][j] -= k;
					for (int x = 0; x < m; x++) {
						for (int y = 0; y < n; y++) {
							if (visited[i][j]) continue;
							visited[i][j] = true;
							int res = bfs(i, j, copymap);
							if (ans3 < res) {
								ans3 = res;
							}
						}
					}
					copymap[i][j] += k;
				}
			}
		}
	}
	cout << ans1 << "\n";
	cout << ans2 << "\n";
	cout << ans3 << "\n";
	return 0;
}
