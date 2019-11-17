/*
[BOJ] 1463. 1로 만들기
https://www.acmicpc.net/problem/1463
*/
/*
#include <cstdio>
using namespace std;

#define min(a,b)(a<b?a:b)

int main()
{
	int dp[100001] = { 0, };
	int n;

	scanf("%d", &n);

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	printf("%d\n", dp[n]);

	return 0;
}
*/