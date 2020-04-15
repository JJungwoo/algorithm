/*
[boj] 17135. 캐슬 디펜스
각각의 턴마다 궁수는 하나의 적을 공격하고, 모든 궁수는 동시에 공격한다
같은 적이 여러 궁수에게 공격당할수 있고 궁수가 공격하는 적은 거리가 D이하인 적중에
가장 가까운 적이고, 그러한 적이 여럿일 경우 가장 왼쪽에 적을 공격한다.
궁수의 공격이 끝나고 적이 이동한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define distance(sx, sy, dx, dy) (abs(sx - dx) + abs(sy - dy))
int n, m, d, ans;
int map[15][15], copy_map[15][15];
bool visited[15];
struct monster {
	int x, y, d;
};
bool compare(monster a, monster b) {
	if(a.d == b.d) return a.y < b.y;
	else return a.d < b.d;
}
vector<int> hunter;
void copy() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
}
void solve(int cnt) {
	if (cnt == 3) {
		int kill = 0;
		int size = hunter.size();
		copy();
		for (int i = n; i >= 1; i--) {	// 아래에서 위로 올라감
			vector<monster> monters[3];
			for (int j = 0; j < 3; j++) {
				int sx = i, sy = hunter[j];
				for (int x = 0; x < i; x++) {
					for (int y = 0; y < m; y++) {
						int dis = distance(sx, sy, x, y);
						if (copy_map[x][y] == 1 && dis <= d) {
							monters[j].push_back({ x,y,dis });
						}
					}
				}
				if (monters[j].size() > 0) {
					sort(monters[j].begin(), monters[j].end(), compare);
				}
			}
			for (int j = 0; j < 3; j++) {
				if (monters[j].size() > 0) {
					int tx = monters[j][0].x, ty = monters[j][0].y;
					if (copy_map[tx][ty] != 0) {
						copy_map[tx][ty] = 0;
						kill++;
					}
				}
			}
		}
		if (ans < kill) {
			ans = kill;
		}
		return;
	}

	for (int i = 0; i < m; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		hunter.push_back(i);
		solve(cnt + 1);
		hunter.pop_back();
		visited[i] = false;
	}
}
int main()
{
	io;
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	solve(0);
	cout << ans << "\n";
	return 0;
}


/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, d, ans;
int map[16][16];
bool visited[16];
vector<int> archer;

void move_monster() {
	for (int i = n-1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (map[i][j] == 1 && i == n - 1) {
				map[i][j] = 0;
			}
			else if(map[i][j] == 1) {
				swap(map[i][j], map[i + 1][j]);
			}
		}
	}
}

void print_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

void hunting_monster(int pos) {

}

void dfs(int cnt) {
	if (cnt == 3) {
		for (int i = 0; i < n; i++) {
			vector<pair<int, int> > killed;
			for (int j = 0; j < archer.size(); j++) {

			}
		}
		ans = max(ans, cnt);
		return;
	}

	for (int i = 0; i < m; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		archer.push_back(i);
		dfs(cnt + 1);
		archer.pop_back();
		visited[i] = false;
	}
}

int main() 
{
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	dfs(0);
	cout << ans << "\n";

	return 0;
}
*/