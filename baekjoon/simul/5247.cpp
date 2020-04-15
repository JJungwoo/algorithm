/*
[boj] 5427. 불
불이 먼저 이동
*/

#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define INF 987654321
int w, h, ans;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
char map[1000][1000];
bool visited[1000][1000];
struct obj {
	int x, y, cnt;
};
obj me;
vector<obj> fire;
int fmap[1000][1000];
void solve()
{
	queue<obj> fq;
	for (int i = 0; i < fire.size(); i++) {
		fq.push({ fire[i] });
		fmap[fire[i].x][fire[i].y] = fire[i].cnt;
	}
	while (!fq.empty()) {
		int x = fq.front().x, y = fq.front().y;
		int cnt = fq.front().cnt;
		fq.pop();
		for (int i = 0; i < 4; i++) {
			int mx = x + dir[i][0], my = y + dir[i][1];
			if (map[mx][my] == '#') continue;
			if (mx < 0 || my < 0 || mx >= h || my >= w) continue;
			if (fmap[mx][my] != 0) continue;
			fmap[mx][my] = cnt + 1;
			fq.push({ mx, my, cnt + 1 });
		}
	}

	/*
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << fmap[i][j] << " ";
		}
		cout << "\n";
	}
	*/

	queue<obj> mq;
	bool visited[1000][1000];
	memset(visited, 0, sizeof(visited));
	mq.push({ me.x, me.y, 1 });
	visited[me.x][me.y] = true;
	while (!mq.empty()) {
		int x = mq.front().x, y = mq.front().y;
		int cnt = mq.front().cnt;
		mq.pop();
		//cout << x << "," << y << ":"<<cnt<<"\n";
		if (x == h - 1 || x == 0 || y == 0 || y == w - 1) {
			if (ans > cnt) {
				ans = cnt;
			}
		}
		for (int i = 0; i < 4; i++) {
			int mx = x + dir[i][0], my = y + dir[i][1];
			if (fmap[mx][my] <= cnt + 1 && fmap[mx][my] >= 1) continue;
			if (map[mx][my] != '.') continue;
			if (visited[mx][my]) continue;
			visited[mx][my] = true;
			mq.push({ mx,my,cnt + 1 });
		}
	}
}
int main()
{	
	io;
	int t;
	cin >> t;
	while (t--) {
		ans = INF;
		cin >> w >> h;
		fire.clear();
		memset(fmap, 0, sizeof(fmap));
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
				if (map[i][j] == '@') {
					me.x = i, me.y = j;
				}
				else if (map[i][j] == '*') {
					fire.push_back({ i, j, 1 });
				}
			}
		}
		solve();
		if (ans == INF) cout << "IMPOSSIBLE\n";
		else cout << ans << "\n";
	}
	
	return 0;
}
