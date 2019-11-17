/*
[BOJ] 9465. 스티커
https://www.acmicpc.net/problem/9465
*
// https://private-space.tistory.com/26, https://rebas.kr/834
#include <cstdio>

#define max(a,b,c)((a>b)?(a>c?a:c):(b>c?b:c))

int sticker[2][100001] = { 0, };
int dp[3][100001] = { 0, };
// [0]: 떼지않음, [1]: 현재 열의 위쪽, [2]: 현재 열의 아래쪽

int main()
{
	int t;

	for (scanf("%d", &t); t > 0; t--)
	{
		int n;
		scanf("%d", &n);

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++)
				scanf("%d", &sticker[i][j]);
		}
		
		dp[0][0] = 0;
		dp[1][0] = sticker[0][0];
		dp[2][0] = sticker[1][0];

		for (int i = 1; i < n; ++i) {
			dp[0][i] = max(dp[0][i - 1], dp[1][i - 1], dp[2][i - 1]);
			dp[1][i] = (max(dp[0][i - 1], 0, dp[2][i - 1])) + sticker[0][i];
			dp[2][i] = (max(dp[0][i - 1], dp[1][i - 1], 0)) + sticker[1][i];
		}
		printf("%d\n", max(dp[0][n - 1], dp[1][n - 1], dp[2][n - 1]));
	}
	return 0;
}

*/