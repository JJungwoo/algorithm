/*
[BOJ] 11052. 카드 구매하기
https://www.acmicpc.net/problem/11052
*/
/*
#include <cstdio>
using namespace std;

#define max(a,b)(a>b?a:b)

int main() {
	int dp[1001] = { 0, };
	int p[1001] = { 0, };
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	
	dp[1] = p[1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i-j] + p[j]);
		}
	}
	printf("%d\n", dp[n]);

	return 0;
}
*/