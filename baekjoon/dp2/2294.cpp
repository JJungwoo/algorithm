/*
[BOJ] 2294. µ¿Àü 2
https://www.acmicpc.net/problem/2294
*
#include <iostream>
using namespace std;

#define min(a,b)(a<b?a:b)
int n, k;
int arr[101] = { 0, };
int dp[10001];
int main()
{	
	scanf("%d %d", &n, &k);
	memset(dp, 10001, sizeof(dp));
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		for (int j = arr[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - arr[i]] + 1);
			printf("%d: %d\n", j, dp[j]);
		}
	}

	printf("%d\n", dp[k]);
	

	return 0;
}
*/




