/*
[BOJ] 7576. ≈‰∏∂≈‰
https://www.acmicpc.net/problem/7576
*/
/*
#include <iostream>
#include <vector>
using namespace std;

int box[1000][1000];
int visit[1000][1000];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int bfs(int x, int y, int depth)
{
	vector<pair<int, int> > vp;
	vp.push_back(make_pair(x, y));

	if (!visit[x][y])
		visit[x][y] = 1;
	
	while (!vp.empty()) {
		for (int i = 0; i < 4; i++) {
			if(visit[x][y] != 0)
				bfs(x + dx[i], y + dy[i], depth + 1);
		}
	}

}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &box[i][j]);
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] != 0)
				bfs(i, j, 0);
		}
	}

	return 0;
}
*/