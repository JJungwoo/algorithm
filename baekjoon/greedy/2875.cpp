/*
[boj] 2875. 대회 or 인턴
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, m, k;
int main()
{
	io;
	cin >> n >> m >> k;
	int ans = 0;
	int total = n + m - k;

	while (n - 2 >= 0 && m - 1 >= 0 && total - 3 >= 0) {
		n -= 2;
		m--;
		total -= 3;
		ans++;
	}
	cout << ans << "\n";
	return 0;
}

