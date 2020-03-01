/*
[BOJ] 17471. 게리맨더링
구역을 두 개의 선거구로 나눠야 하고, 각 구역은 두 선거구 중 하나에 포함되어야 한다.
선거구는 구역을 적어도 하나 포함해야 하고, 한 선거구에 포함되어 있는 구역은 모두 연결되어야 한다.

*/

//https://travelbeeee.tistory.com/286
//https://grini25.tistory.com/154
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, parr[11], ans;
bool visited[11];

vector<vector<pair<int, int> > > vp;
vector<int> a, b;
bool checkSection(vector<int> &tmp) {
}
void calcVote() {
	int asum = 0, bsum = 0;
	if (checkSection(a) && checkSection(b)) {
		for (int i = 0; i < a.size(); i++) {
			asum += parr[a[i]];
		}
		for (int i = 0; i < b.size(); i++) {
			bsum += parr[b[i]];
		}
		ans = min(ans, abs(asum - bsum));
	}
}
void dfs(int cnt) {
	if (cnt > n) return;
	if (cnt == n) {
		calcVote();
		return;
	}
	a.push_back(cnt+1);
	dfs(cnt + 1);
	a.pop_back();
	b.push_back(cnt + 1);
	dfs(cnt + 1);
	b.pop_back();
}
int main()
{
	cin >> n;
	vp.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> parr[i];
	}
	for (int i = 1; i <= n; i++) {
		int tmp; cin >> tmp;
		for (int j = 1; j <= tmp; j++) {
			int section; cin >> section;
			vp[i].push_back(make_pair(section, parr[section]));
		}
	}
	dfs(0);
	return 0;
}