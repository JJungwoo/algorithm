/*
wrong answer on test 4

#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int n, ch = 0;
	int a[15001] = { 0, }; // 150001
	int dp[15001] = { 0, };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	if (n == 1)
		printf("1\n");
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i - 1] + 1) ch = 1;
		else break;
	}
	if (ch == 1) { 
		printf("%d\n", n);
		return 0;
	}

	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			dp[a[i]] = 1;
			dp[a[i] + 1] = 1;
		}
		else if(a[i] == a[i-1]){
			dp[a[i] + 1] = 1;
			dp[a[i] - 1] = 1;
			dp[a[i]] = 1;
			i++;
		}
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (dp[i] >= 1)
			ans++;
	}
	printf("%d\n", ans);

	return 0;
}
*/