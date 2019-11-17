/*
[BOJ] 11057. 오르막 수
https://www.acmicpc.net/problem/11057

#include <cstdio>
using namespace std;

#define max(a,b)(a>b?a:b)

int main() {

	int n;
	int arr[1001] = { 0, };
	int dp[1001] = { 0, };
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (arr[i] < arr[j])
				dp[i] = max(dp[i], dp[j]+1);
		}
	}
	printf("%d\n", dp[n - 1]);

	return 0;
}

*/