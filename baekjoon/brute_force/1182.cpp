/*
[boj] 1182. 부분수열의 합
*/
#include <iostream>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int n, s, ans;
int numbers[20];
void solve(int num, int sum){
	if (num > n) return;
	if (sum == s && num == n) {
		ans++;
		return;
	}
	solve(num + 1, sum + numbers[num]);
	solve(num + 1, sum);
}
int main()
{
	io;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	solve(0, 0);
	if (s == 0) ans--;
	cout << ans << "\n";
	return 0;
}