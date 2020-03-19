/*
[boj] 15684. 사다리 조작
단, 두 가로선이 연속하거나 서로 접하면 안 된다. 또, 가로선은 점선 위에 있어야 한다.
가로선을 만나면 가로선을 이용해 옆 세로선으로 이동한 다음, 이동한 세로선에서 아래 방향으로 이동해야 한다.
*/

#include <iostream>
#include <cstring>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int n, m, h, ans = 987654321, ncnt;	// 세로, 가로 선의 수, 가로 사다리 끝 위치
int map[1][31][11];
bool visited[31][11];

void print_map() {
	cout << "print_map\n";
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < n; x++) {
			cout << map[0][y][x] << " ";
		}
		cout << "\n";
	}
}

void solve(int cur, int cnt) {
	if (cur == cnt) {
		for (int x = 0; x < n; x++) {
			
			int mx = x;
			for(int my = 0; my < h; my++) {
				if (mx + 1 < n && map[0][my][mx] == map[0][my][mx + 1]
					&& map[0][my][mx] != 0 && map[0][my][mx + 1] != 0 ) {
					mx += 1;
				}
				else if (mx - 1 >= 0 && map[0][my][mx] == map[0][my][mx - 1]
					&& map[0][my][mx] != 0 && map[0][my][mx - 1] != 0) {
					mx -= 1;
				}
			}

			if (mx != x) {
				//cout << "x:" << x << ", mx:" << mx <<"\n";
				return;
			}
		}
		ans = cnt;
		return;
	}

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < n - 1; x++) {
			if (map[0][y][x] != 0 || map[0][y][x+1] != 0) continue;
			map[0][y][x] = ncnt + cur;
			map[0][y][x + 1] = ncnt + cur;
			solve(cur + 1, cnt);
			map[0][y][x] = 0;
			map[0][y][x + 1] = 0;
		}
	}
}

int main()
{
	io;
	cin >> n >> m >> h;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		map[0][a][b] = i;
		map[0][a][b + 1] = i;
	}
	ncnt = m + 1;
	if (m == 0) {
		cout << "0\n";
		return 0;
	}
	//print_map();
	for (int i = 0; i < 4; i++) {
		solve(0, i);
		if (ans != 987654321) break;
	}
	if (ans == 987654321) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}



/*
#include <iostream>
#include <cstring>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int n, m, h, ans = 987654321, ncnt;	// 세로, 가로 선의 수, 가로 사다리 끝 위치
int map[1][31][11];
bool visited[31][11];

void solve(int cur, int cnt) {
	if (cur == cnt) {
		for (int x = 0; x < n; x++) {
			int mx = x;
			for (int my = 0; my < h; my++) {
				if (mx + 1 < n && map[0][my][mx] == map[0][my][mx + 1]
					&& map[0][my][mx] != 0 && map[0][my][mx + 1] != 0) {
					mx += 1;
				}
				else if (mx - 1 >= 0 && map[0][my][mx] == map[0][my][mx - 1]
					&& map[0][my][mx] != 0 && map[0][my][mx - 1] != 0) {
					mx -= 1;
				}
			}

			if (mx != x) {
				return;
			}
		}
		ans = cnt;
		return;
	}

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < n - 1; x++) {
			if (map[0][y][x] != 0 || map[0][y][x + 1] != 0) continue;
			if (visited[y][x] || visited[y][x + 1]) continue;
			visited[y][x] = true;
			visited[y][x + 1] = true;
			map[0][y][x] = ncnt + cur;
			map[0][y][x + 1] = ncnt + cur;
			solve(cur + 1, cnt);
			map[0][y][x] = 0;
			map[0][y][x + 1] = 0;
			visited[y][x] = false;
			visited[y][x + 1] = false;
		}
	}

}

int main()
{
	io;
	cin >> n >> m >> h;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		map[0][a][b] = i;
		map[0][a][b + 1] = i;
		visited[a][b] = true;
		visited[a][b + 1] = true;
	}
	ncnt = m + 1;
	if (m == 0) {
		cout << "0\n";
		return 0;
	}
	for (int i = 1; i <= 3; i++) {
		solve(0, i);
		if (ans != 987654321) break;
	}
	if (ans == 987654321) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}
*/