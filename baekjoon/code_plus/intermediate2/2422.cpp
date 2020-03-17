/*
[boj] 2422. 한윤정이 이탈리아에 가서 아이스크림을 사먹는데
*/
#include <iostream>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, m, ans;
bool visited[201];
bool check[201][201];
vector<int> v, map[201];
void solve(int cur, int cnt) {
	if (cnt > 3) return;
	if (cnt == 3) {
		int size = v.size();
		for (int i = 0; i < size; i++) {
			vector<int> tmp = map[v[i]];
			int map_size = tmp.size();
			for (int j = 0; j < map_size; j++) {
				if (visited[tmp[j]]) return;
			}
		}
		ans++;
		return;
	}
	for (int i = cur; i <= n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		v.push_back(i);
		solve(i + 1, cnt + 1);
		v.pop_back();
		visited[i] = false;
	}
}
int main()
{
	io;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}
	solve(1, 0);
	cout << ans << "\n";
	return 0;
}