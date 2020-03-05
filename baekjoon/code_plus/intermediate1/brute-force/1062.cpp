/*
[boj] 1062. 가르침
*/
#include <iostream>
#include <vector>
#include <string>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
bool visited[26];	// a,b,c,d,e ~
int n, k, ans;
vector<string> vs;
vector<int> check_word_vector;
void solve(int cnt, int idx) {
	if (cnt == k) {
		int total = 0;
		int vs_size = vs.size();
		for (int i = 0; i < vs_size; i++) {
			string stmp = vs[i];
			bool check = true;
			int stmp_size = stmp.size();
			for (int j = 0; j < stmp_size; j++) {
				if (!visited[stmp[j] - 'a']) {
					//cout << i << "," << j << "," << stmp[j] << "\n";
					check = false;
					break;
				}
			}
			if (check) total++;
		}
		if (ans < total) {
			ans = total;
		}
		return;
	}
	for (int i = idx; i < 26; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		solve(cnt + 1, i + 1);
		visited[i] = false;
	}
}
int main()
{
	io;
	cin >> n >> k;
	if (k < 5) {
		cout << 0 << '\n';
		return 0;
	}
	else if (k == 26) {
		cout << n << '\n';
		return 0;
	}
	for (int i = 0; i < n; i++) {
		string stmp; cin >> stmp;
		vs.push_back(stmp);
	}	
	visited['a' - 'a'] = visited['n' - 'a'] = visited['t' - 'a'] = visited['i' - 'a'] = visited['c' - 'a'] = 1;
	k -= 5;
	solve(0, 0);
	cout << ans << "\n";
	return 0;
}