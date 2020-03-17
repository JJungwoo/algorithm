/*
[boj] 15686. 치킨 배달
1부터 세로 r 1, 2, 3, 가로 c 1, 2, 3, ..
(r1,c1) <-> (r2,c2) = |r1-r2| + |c1-c2|
각 치킨집의 거리를 구해서 가장 총거리량이 작은 치킨집이 답
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
struct rest {
	int x, y;
	rest(int _x, int _y) :x(_x), y(_y) {};
};
int n, m, ans = 987654321;
int map[51][51];
vector<rest> vr, sel, home;
bool visited[51][51];
inline int cal_distance(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}
void copy_map(int tmp_map[51][51]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp_map[i][j] = map[i][j];
		}
	}
}
int cal_map(int tmp_map[51][51]) {
	int dis = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				dis += tmp_map[i][j];
			}
		}
	}
	return dis;
}
void find_distance() {
	int size = sel.size();
	int tmp_map[51][51];
	memset(tmp_map, 102, sizeof(tmp_map));
	for (int i = 0; i < size; i++) {
		int hsize = home.size();
		for (int j = 0; j < hsize; j++) {
			int dis = cal_distance(sel[i].x, sel[i].y, home[j].x, home[j].y);
			if (dis < tmp_map[home[j].x][home[j].y]) {
				tmp_map[home[j].x][home[j].y] = dis;
			}
		}
	}
	int total_distance = cal_map(tmp_map);
	if (ans > total_distance) {
		ans = total_distance;
	}
}
void solve(int cur, int cnt) {
	if (cnt > m) return;
	if (cnt == m) {
		find_distance();
		return;
	}
	int size = vr.size();
	for (int i = cur; i < size; i++) {
		if (visited[vr[i].x][vr[i].y]) continue;
		visited[vr[i].x][vr[i].y] = true;
		sel.push_back(rest(vr[i]));
		solve(i + 1, cnt + 1);
		sel.pop_back();
		visited[vr[i].x][vr[i].y] = false;
	}
}
int main()
{
	io;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				vr.push_back(rest(i, j));
			}
			else if (map[i][j] == 1) {
				home.push_back(rest(i, j));
			}
		}
	}
	solve(0, 0);
	cout << ans << "\n";
	return 0;
}
/*
// dfs 풀이 
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
struct rest {
	int x, y;
	rest(int _x, int _y) :x(_x), y(_y) {};
};
int n, m, ans = 987654321;	
int map[51][51];
vector<rest> vr, sel;
bool visited[51][51], qvisited[51][51];
inline int cal_distance(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}
void copy_map(int tmp_map[51][51]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp_map[i][j] = map[i][j];
		}
	}
}
bool check_map(int tmp_map[51][51]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tmp_map[i][j] == 1) {
				return false;
			}
		}
	}
	return true;
}
void bfs() {
	int tmp_map[51][51], distance = 0;
	queue<pair<rest, rest> > qr;	// des, src
	int size = sel.size();
	for (int i = 0; i < size; i++) {
		qr.push(make_pair(rest(sel[i]), rest(sel[i])));
	}
	copy_map(tmp_map);
	memset(qvisited, 0, sizeof(qvisited));
	while (!qr.empty()) {
		int sx = qr.front().second.x, sy = qr.front().second.y;
		int x = qr.front().first.x, y = qr.front().first.y;
		qr.pop();
		if (check_map(tmp_map)) {
			if (ans > distance) {
				ans = distance;
				return;
			}
		}
		for (int i = 0; i < 4; i++) {
			int mx = x + dir[i][0], my = y + dir[i][1];
			if (mx < 0 || my < 0 || mx >= n || my >= n) continue;
			if (qvisited[mx][my]) continue;
			if (tmp_map[mx][my] == 1) {
				distance += cal_distance(mx, my, sx, sy);
				tmp_map[mx][my] = 0;
			}
			qvisited[mx][my] = true;
			qr.push(make_pair(rest(mx, my), rest(sx, sy)));
		}
	}
}
void solve(int cur, int cnt) {
	if (cnt > m) return;
	if (cnt == m) {
		bfs();
		return;
	}
	int size = vr.size();
	for (int i = cur; i < size; i++) {
		if (visited[vr[i].x][vr[i].y]) continue;
		visited[vr[i].x][vr[i].y] = true;
		sel.push_back(rest(vr[i]));
		solve(cur + 1, cnt + 1);
		sel.pop_back();
		visited[vr[i].x][vr[i].y] = false;
	}
}
int main()
{
	io;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				vr.push_back(rest(i, j));
			}
		}
	}
	solve(0, 0);
	cout << ans << "\n";
	return 0;
}
*/