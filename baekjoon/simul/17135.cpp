/*
[boj] 17135. 캐슬 디펜스
각각의 턴마다 궁수는 하나의 적을 공격하고, 모든 궁수는 동시에 공격한다
같은 적이 여러 궁수에게 공격당할수 있고 궁수가 공격하는 적은 거리가 D이하인 적중에
가장 가까운 적이고, 그러한 적이 여럿일 경우 가장 왼쪽에 적을 공격한다.
궁수의 공격이 끝나고 적이 이동한다.
disk = |n - i| + |k - j|
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, m, d, ans;
int map[16][16];
bool visited[16];
vector<int> archer;

struct castle{
    int x, y, z;
    bool operator < (const castle &t) const {
        if(z == t.z) return y > t.y;
        else return z > t.z;
    }
};

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