/*
[BOJ] 11727. 2xn ≈∏¿œ∏µ 2
https://www.acmicpc.net/problem/11727
*/
/*
#include <cstdio>
using namespace std;

int main() {
	int dp[1001] = { 0, };
	int n;
	scanf("%d", &n);

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 3;

	if (n == 1)
		printf("1\n");
	else {
		for (int i = 3; i <= n; i++) {
			dp[i] = (dp[i - 1] + 2*dp[i - 2]) % 10007;
		}

		printf("%d\n", dp[n]);
	}
	return 0;
}
*/