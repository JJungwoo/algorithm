/*
[boj] 9466. 텀 프로젝트
시간초과.. 
*/
#include <iostream>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int t, n;
vector<int> v[100001];
void init(int n) {
	for (int i = 1; i <= n; i++) {
		v[i].clear();
	}
}
bool cycle(int idx, int des, int cnt) {
	if (idx == des && cnt > 0) {
		return true;
	}
	else if (cnt > n) return false;
	int size = v[idx].size();
	for (int i = 0; i < size; i++) {
		if (cycle(v[idx][i], des, cnt + 1)) return true;
	}
	return false;
}
int main()
{
	io;
	cin >> t;
	while (t--) {
		int ans = 0, value;
		cin >> n;
		init(n);
		for (int i = 1; i <= n; i++) {
			cin >> value;
			v[i].push_back(value);
		}
		for (int i = 1; i <= n; i++) {
			if (cycle(i, i, 0) == false) ans++;
		}		
		cout << ans << "\n";
	}
	
	return 0;
}
