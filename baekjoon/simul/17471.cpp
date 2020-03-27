/*
[boj] 17471. 게리맨더링
//https://travelbeeee.tistory.com/286
//https://grini25.tistory.com/154
*/

#include <iostream>
#include <vector>
#include <queue>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int n, ans = 987654321;
vector<int> section[11];
int map[11];
vector<int> teamA, teamB;

inline bool check_team(vector<int> tmp, int move) {
	int size = tmp.size();
	for (int i = 0; i < size; i++) {
		if (tmp[i] == move) {
			return true;
		}
	}
	return false;
}

int check_section(vector<int> tmp) {
	int tsize = tmp.size();
	int sum = map[tmp[0]], cnt = 1;
	int visited[11] = { 0, };
	queue<int> q;
	q.push(tmp[0]);
	visited[tmp[0]] = true;
	while (!q.empty()) {
		int go = q.front();
		q.pop();
		int size = section[go].size();
		for (int i = 0; i < size; i++) {
			int move = section[go][i];
			if (visited[move]) continue;
			if (!check_team(tmp, move)) continue;
			q.push(move);
			visited[move] = true;
			sum += map[move];
			cnt++;
		}
	}
	if (cnt == tsize) return sum;
	else return 0;
}

void solve(int cnt) {
	if (cnt == n) {
		if (teamA.empty() || teamB.empty()) return;
		int acnt = check_section(teamA);
		int bcnt = check_section(teamB);
		if (acnt != 0 && bcnt != 0) {
			int res = abs(acnt - bcnt);
			if (ans > res) {
				ans = res;
			}
		}
		return;
	}

	teamA.push_back(cnt);
	solve(cnt + 1);
	teamA.pop_back();

	teamB.push_back(cnt);
	solve(cnt + 1);
	teamB.pop_back();
	
}

int main()
{
	io;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> map[i];
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		for (int j = 0; j < tmp; j++) {
			int close; cin >> close;
			close--;
			section[i].push_back(close);
		}
	}

	solve(0);
	if (ans == 987654321) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
*/