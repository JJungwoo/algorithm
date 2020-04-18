/*
[boj] 14225. 부분수열의 합
*/

#include <iostream>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int s, ans = 1;
vector<int> seq;
bool visited[2000001];
void solve(int num, int sum) {
	if (num > s) return;
	if (num == s) {
		visited[sum] = true;
		if (ans < sum) {
			ans = sum;
		}
		return;
	}

	solve(num + 1, sum + seq[num]);
	solve(num + 1, sum);
}
int main()
{
	io;
	cin >> s;
	seq.resize(s);
	for (int i = 0; i < s; i++) {
		cin >> seq[i];
	}
	solve(0, 0);
	bool find = false;
	for (int i = 1; i <= ans; i++) {
		if (visited[i]) continue;
		find = true;
		cout << i << "\n";
		break;
	}
	if (!find) cout << ans + 1 << "\n";
	return 0;
}
