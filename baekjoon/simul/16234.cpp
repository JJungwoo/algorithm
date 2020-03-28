/*
[boj] 16234. 인구 이동
*/

#include <iostream>
#include <cstring>
#include <queue>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int n, l, r, ans, cnt;
int map[50][50];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
bool visited[50][50];
bool move_check;

inline bool gocheck(int val1, int val2) {
	int diff = abs(val1 - val2);
	if (diff >= l && diff <= r) return true;
	return false;
}

int cal_population(int x, int y, vector<pair<int, int> > &vp) {
	int sum = map[x][y];
	queue<pair<int, int> > qp;
	qp.push(make_pair(x, y));
	visited[x][y] = true;
	while (!qp.empty()) {
		int dx = qp.front().first, dy = qp.front().second;
		qp.pop();
		for (int i = 0; i < 4; i++) {
			int mx = dx + dir[i][0], my = dy + dir[i][1];
			if (mx < 0 || my < 0 || mx >= n || my >= n) continue;
			if (visited[mx][my]) continue;
			if (!gocheck(map[mx][my], map[dx][dy])) continue;
			visited[mx][my] = true;
			sum += map[mx][my];
			qp.push(make_pair(mx, my));
			vp.push_back(make_pair(mx, my));
			cnt++;
		}
	}
	if (sum == map[x][y]) return 0;
	return sum;
}

void print_map() {
	cout << "print_map\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

void solve() {
	while (1) {
		memset(visited, 0, sizeof(visited));
		move_check = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j]) continue;
				vector<pair<int, int> > vp;
				vp.push_back(make_pair(i, j));
				cnt = 1;
				int total = cal_population(i, j, vp);
				if (total != 0) {
					int value = total/cnt;
					int size = vp.size();
					for (int v = 0; v < size; v++) {
						map[vp[v].first][vp[v].second] = value;
					}
					move_check = true;
				}
			}
		}
		if(move_check) ans++;
		else break;
	}
}

int main()
{
	io;
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	cout << ans << "\n";
	return 0;
}


/*
#include <iostream>
#include <cstring>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int n, l, r, ans, cnt, total;
int map[51][51];
bool visited[51][51], team[51][51];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };


inline bool check_move(int x1, int y1, int x2, int y2) {
	int diff = abs(map[x1][y1] - map[x2][y2]);
	if (diff >= l && diff <= r) return true;
	return false;
}

void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int mx = x + dir[i][0], my = y + dir[i][1];
		if (mx < 0 || my < 0 || mx >= n || my >= n) continue;
		if (team[mx][my]) continue;
		if (!check_move(x, y, mx, my)) continue;
		team[mx][my] = true;
		cnt++;
		total += map[mx][my];
		dfs(mx, my);
	}
}

void divide(int val) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (team[i][j]) {
				//cout << i << "," << j << "," << val << "\n";
				map[i][j] = val;
				team[i][j] = false;
			}
		}
	}
}

void print_map() {
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

bool check_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//total = 0;
			if (!visited[i][j]) {
				visited[i][j] = true;
				total = map[i][j];
				cnt = 1;
				dfs(i, j);	// 방문 체크
				if (cnt > 1) {		// 값을 나눌 나라가 존재
					int div_val = total / cnt;
					//cout << cnt << "," << total << "\n";
					divide(div_val);
					//check = true;
					return true;
				}
			}
		}
	}
	return false;
}

void solve() {
	while (true) {
		bool check = false;
		memset(visited, 0, sizeof(visited));
		if (check_map()) {
			ans++;
		}
		else break;
		print_map();
		//cout << ans << "\n";
		//if (check) ans++;
		
	}
}

int main()
{
	io;
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	solve();
	cout << ans << "\n";

	return 0;
}
*/