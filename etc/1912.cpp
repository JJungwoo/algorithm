/*
baekjoon 1912번 연속합.
*/
/*
#include <iostream>
#include <algorithm>
using namespace std;
int n, ans;
int seq[100001];
int dp[100001];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> seq[i];

	ans = -1001;
	dp[0] = seq[0];
	for (int i = 1; i < n; i++) {

		if (dp[i - 1] + seq[i] > seq[i])
			dp[i] = seq[i] + dp[i - 1];
		else
			dp[i] = seq[i];

		ans = max(ans, dp[i]);
	}
	ans = max(ans, dp[0]);

	cout << ans << endl;

	return 0;
}
*/