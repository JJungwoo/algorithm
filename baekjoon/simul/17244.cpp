/*
[boj] 17244. 아맞다우산
sort를 사용해서 물건의 위치중 가장 가까운것 먼저 찾는 방식을 사용하였는데, 문제는 거리를 구할 때 
내위치와 물건사이에 벽을 생각못했다... 이런;
물건 갯수는 최대 5개이니까 그냥 5개 찾아가는 순서만 돌리면 되는것이였음을..
*/
/*
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
inline int distance(int sx, int sy, int dx, int dy) {
	return abs(sx - dx) + abs(sy - dy);
}
int myX, myY, endx, endy;
int n, m, xcnt, ans;
char map[51][51];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
struct xlist {
	int x, y, cnt;
};
vector<xlist> v;
bool compare(xlist a, xlist b) {
	return distance(myX, myY, a.x, a.y) < distance(myX, myY, a.x, a.y);
}
void bfs()
{
	int cnt = 0, find = 0;
	while (1) {
		queue<xlist> q;
		q.push({ myX, myY, 0 });
		int tx = v[0].x , ty = v[0].y;
		bool visited[51][51];
		memset(visited, 0, sizeof(visited));
		while (!q.empty()) {
			int x = q.front().x, y = q.front().y;
			int mcnt = q.front().cnt;
			q.pop();
			if (x == tx && y == ty) {
				myX = x, myY = y;
				cnt += mcnt;
				find++;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int mx = x + dir[i][0], my = y + dir[i][1];
				if (map[mx][my] == '#') continue;
				if (visited[mx][my]) continue;
				visited[mx][my] = true;
				q.push({ mx, my, mcnt + 1 });
			}
		}
		if (find == xcnt) {
			ans = cnt + distance(myX, myY, endx, endy);
			break;
		}
		v.erase(v.begin());
		if(!v.empty()) sort(v.begin(), v.end(), compare);
	}
}

int main()
{
	io;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				myX = i, myY = j;
			}
			else if (map[i][j] == 'X') {
				v.push_back({ i, j, 0 });
				xcnt++;
			}
			else if (map[i][j] == 'E') {
				endx = i, endy = j;
			}
		}
	}
	if (xcnt == 0) {
		ans = distance(myX, myY, endx, endy);
	}else{
		sort(v.begin(), v.end(), compare);
		bfs();
	}
	cout << ans << "\n";
	return 0;
}
*/

#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int myX, myY, endX, endY;
int n, m, xcnt, ans, minans = 987654321;
char map[51][51];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
struct checklist {
	int x, y, mvcnt;
};
vector<checklist> v, sv;
void bfs(int tx, int ty) 
{
	bool visited[51][51];
	memset(visited, 0, sizeof(visited));
	queue<checklist> q;
	q.push({ myX,myY,0 });
	visited[myX][myY] = true;
	while (!q.empty()) {
		int dx = q.front().x, dy = q.front().y;
		int mvcnt = q.front().mvcnt;
		q.pop();
		if (tx == dx && ty == dy){
			myX = tx, myY = ty;
			ans += mvcnt;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int mx = dx + dir[i][0], my = dy + dir[i][1];
			if (map[mx][my] == '#') continue;
			if (visited[mx][my])continue;
			visited[mx][my] = true;
			q.push({ mx,my,mvcnt + 1 });
		}
	}
}

void solve(int cur, int cnt) {
	if (cnt == xcnt) {
		ans = 0;
		int size = sv.size();
		for (int i = 0; i < size; i++) {
			bfs(sv[i].x, sv[i].y);
		}
		bfs(endX, endY);
		if (minans > ans) {
			minans = ans;
		}
		return;
	}

	int size = v.size();
	for (int i = 0; i < size; i++) {
		sv.push_back(v[i]);
		solve(i + 1, cnt + 1);
		sv.pop_back();
	}
}

int main()
{
	io;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S')
				myX = i, myY = j;
			else if (map[i][j] == 'X') {
				v.push_back({ i,j,0 });
				xcnt++;
			}
			else if (map[i][j] == 'E') {
				endX = i, endY = j;
			}
		}
	}
	if(xcnt != 0) solve(0, 0);
	else {
		bfs(endX, endY);
		minans = ans;
	}
	cout << minans << "\n";
	return 0;
}
