/*
[boj] 11441. 합 구하기
*/
#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, m;
int arr[100001], sum[100001];
int main()
{
	io;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << "\n";
	}
	return 0;
}
