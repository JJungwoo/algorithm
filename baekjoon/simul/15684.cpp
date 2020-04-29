/*
[boj] 15684. 사다리 조작
단, 두 가로선이 연속하거나 서로 접하면 안 된다. 또, 가로선은 점선 위에 있어야 한다.
가로선을 만나면 가로선을 이용해 옆 세로선으로 이동한 다음, 이동한 세로선에서 아래 방향으로 이동해야 한다.
만약, 정답이 3보다 큰 값이면 -1을 출력한다. 또, 불가능한 경우에도 -1을 출력한다.

시간초과 해결 방법
copy 함수를 inline 으로 바꿈
세로선 체크할때 하나라도 틀리면 바로 종료하게 수정
*/

#include <iostream>
#include <vector>
#include <cstring>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, m, h, ans = 4, k = 1;	// 세로, 가로, 가로선을 놓을 수 있는 공간
struct pos {
	int x, y;
};
pos column[30];
vector<pos> sel;
int map[30][30], copymap[30][30];
bool visited[30][30];
inline void copy() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			copymap[i][j] = map[i][j];
		}
	}
}
void print() {
	cout << "print \n";
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			cout<< copymap[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
}
void solve(int cnt, int icur) {
	if (cnt > 3) return;
	if (cnt <= 3) {
		copy();
		int tmp = k;
		int ssize = sel.size(), check = 0;
		for (int i = 0; i < ssize; i++) {
			copymap[sel[i].x][sel[i].y] = tmp;
			copymap[sel[i].x][sel[i].y + 1] = tmp++;
		}
		//print();
		for (int i = 0; i < n; i++) {
			int start = i, idx = i;
			for (int j = 0; j < h; j++) {
				if (copymap[j][idx] != 0) {
					if (idx - 1 >= 0 && copymap[j][idx - 1] == copymap[j][idx]) {
						idx--;
					}
					else if (idx + 1 < n && copymap[j][idx + 1] == copymap[j][idx]) {
						idx++;
					}
				}
			}
			if (idx == start) {
				check++;
			}
			else break;
			//cout << "start :" << start << " idx: " << idx << " check:" << check << "\n";
		}
		if (check == n) {
			if (ans > cnt) {
				ans = cnt;
			}
		}
	}

	for (int i = icur; i < h; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (map[i][j] == 0 && map[i][j + 1] == 0 && !visited[i][j] && !visited[i][j+1]) {
				visited[i][j] = true;
				visited[i][j+1] = true;
				sel.push_back({ i, j });
				solve(cnt + 1, i);
				sel.pop_back();
				visited[i][j] = false;
				visited[i][j+1] = false;
			}
		}
	}
	
}
int main()
{
	io;
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		map[x - 1][y - 1] = k;
		map[x - 1][y] = k++;
	}
	solve(0, 0);
	if (ans == 4) cout << "-1\n";
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

*/

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