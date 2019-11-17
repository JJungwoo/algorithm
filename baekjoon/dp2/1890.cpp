/*
[BOJ] 1890. มกวม
https://www.acmicpc.net/problem/1890
*/
/*
#include <iostream>
using namespace std;

typedef long long ll;

int arr[101][101];
ll dp[101][101];
int visit[101][101];
int n;

int main()
{
	scanf("%d", &n);

	for(int i=0;i<n;i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	dp[0][0] = 1;
	visit[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) continue;
			if (i == n - 1 && j == n - 1) break;
			int jump = arr[i][j];
			printf("x: %d, y: %d\n", i, j);
			if (i + jump < n) {
				dp[i + jump][j] += dp[i][j];
				visit[i + jump][j] = 1;
			}
			if (j + jump < n) {
				dp[i][j + jump] += dp[i][j];
				visit[i][j + jump] = 1;
			}
		}
	}
	printf("%lld\n", dp[n-1][n-1]);
	return 0;
}
*/