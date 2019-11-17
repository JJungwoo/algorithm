/*
[BOJ] 10942. ÆÒ¸°µå·Ò?
https://www.acmicpc.net/problem/10942
*/
/*
#include <iostream>
using namespace std;

int n;
int arr[2001] = { 0, };
int dp[2001][2001] = { 0, };
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n - 1; i++) {
		dp[i][i] = 1;
		if (arr[i] == arr[i + 1]) {
			dp[i][i + 1] = 1;
		}
	}
	dp[n][n] = 1;

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n - k + 1; i++) {
			int j = i + k - 1;
			if (arr[i] == arr[j] && dp[i + 1][j - 1] == 1)
				dp[i][j] = 1;
		}
	}

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		if (dp[s][e]) printf("1\n");
		else printf("0\n");
	}
	return 0;
}
*/