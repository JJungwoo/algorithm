/*
[boj] 1806. 부분합
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, s, minlen = 100001, len;
int arr[10001], sum[10001];
int main()
{
	io;
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (i == 0) sum[i] = arr[i];
		else sum[i] = sum[i - 1] + arr[i];
	}
	int i = 1, j = 1;
	while (!(n == i && i == j)) {
		if (sum[j] - sum[i - 1] >= s) {
			len = j - i + 1;
			if (minlen > len)
				minlen = len;
			i++;
		}
		else if (sum[j] - sum[i - 1] < s) {
			if (j < n) j++;
			else i++;
		}
	}

	if (minlen == 100001) cout << "0\n";
	else cout << minlen << "\n";

	return 0;
}
