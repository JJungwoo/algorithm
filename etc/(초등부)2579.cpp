/*
[BOJ] 2579. 계단 오르기
https://www.acmicpc.net/problem/2579
*/
/*
#include <iostream>
using namespace std;

#define max(a,b)(a>b?a:b)
int main()
{
	int n;
	int arr[300] = { 0, };
	int dp[300] = { 0, };
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	dp[1] = arr[1];
	dp[2] = arr[2];

	for (int i = 2; i <= n; i++) {
		dp[i] = max(arr[i - 1] + dp[i - 3], dp[i - 2]) + arr[i];
	}
	printf("%d\n", dp[n]);

	return 0;
}
*/