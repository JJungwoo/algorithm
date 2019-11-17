/*
[BOJ] 2293. µ¿Àü 1
https://www.acmicpc.net/problem/2293
*/
/*
#include <iostream>
using namespace std;

int main()
{
	int n, k;
	int arr[101] = { 0, };
	int dp[10001] = { 1, };
	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		for (int j = arr[i]; j <= k; j++) {
			dp[j] += dp[j - arr[i]];
		}
	}
	printf("%d\n", dp[k]);

	return 0;
}
*/