/*
baekjoon 2178¹ø ¹Ì·Î Å½»ö.
*/
/*
#include <iostream>
#include <queue>
#pragma warning(disable:4996)
using namespace std;
int N, M;
int map[101][101];
int dir[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
queue< pair<int, int> > q;

void bfs()
{
	q.push(make_pair(0, 0));
	pair<int, int> cur;
	int x, y;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			x = cur.first + dir[i][0];
			y = cur.second + dir[i][1];
			if (x >= 0 && x < N && y >= 0 && y < M && map[x][y] == 1) {
				q.push(make_pair(x, y));
				map[x][y] = map[cur.first][cur.second] + 1;
			}
		}
	}
	return;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf_s("%1d", &map[i][j]);
	
	bfs();
	
	cout << map[N - 1][M - 1] << endl;

	return 0;
}
*/