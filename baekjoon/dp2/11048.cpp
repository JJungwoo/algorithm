/*
[BOJ] 11048. 이동하기
https://www.acmicpc.net/problem/11048
*

#include <iostream>
#include <queue>

#define max(a,b)(a>b?a:b)

using namespace std;

int map[1000][1000];
int dp[1000][1000];
int ans, n, m;

void dfs() {

}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	dfs();

	return 0;
}
/*
#include <iostream>
#include <queue>

#define max(a,b)(a>b?a:b)

using namespace std;

int map[1000][1000];
int dp[1000][1000];
int ans, n, m;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int x, y;
	while (1) {
		if (y >= n || x >= m)
			break;
		if (x + 1 < m) {
			dp[y][x + 1] = max(dp[y][x + 1], map[y][x + 1] + dp[y][x]);
		}
		if (y + 1 < n) {
			dp[y + 1][x] = max(dp[y + 1][x], map[y + 1][x] + dp[y][x]);
		}
		if (x + 1 < m && y + 1 < n) {
			dp[y + 1][x + 1] = max(dp[y + 1][x + 1], map[y + 1][x + 1] + dp[y][x]);
		}
		ans = max(ans, dp[y][x]);
	}

	return 0;
}

/*

#include <iostream>
#include <queue>

#define max(a,b)(a>b?a:b)

using namespace std;

int map[1000][1000];
int dp[1000][1000];
int ans, n, m;

void find(int x, int y) {
	if (y >= n || x >= m)
		return;

	if (x + 1 < m) {
		dp[y][x + 1] = max(dp[y][x + 1], map[y][x + 1] + dp[y][x]);
		find(x + 1, y);
	}
	if (y + 1 < n) {
		dp[y + 1][x] = max(dp[y + 1][x], map[y + 1][x] + dp[y][x]);
		find(x, y + 1);
	}
	if (x + 1 < m && y + 1 < n) {
		dp[y + 1][x + 1] = max(dp[y + 1][x + 1], map[y + 1][x + 1] + dp[y][x]);
		find(x + 1, y + 1);
	}
	ans = max(ans, dp[y][x]);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	dp[0][0] = 1;
	find(0,0);
	printf("%d\n", ans);
	
	return 0;
}
*/