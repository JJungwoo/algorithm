/*
[boj] 3190. 뱀 
https://www.acmicpc.net/problem/3190
*/
#include <iostream>
#include <vector>
#include <queue>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, k, l, ans;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
vector<pair<int, char> > cmds;
struct snake {
	int x, y;
    snake(int _x, int _y):x(_x), y(_y){}
};
int map[100][100];
void solve()
{
	queue<snake> q;
	q.push(snake( 0,0 ));
	map[0][0] = 2;
	int x = 0, y = 0, d = 0, cnt = 0;
	while (true) {
		x += dir[d][0], y += dir[d][1];
		ans++;
		if (x < 0 || y < 0 || x >= n || y >= n || map[x][y] == 2) {
			break;
		}
		if (map[x][y] != 1){
			int tx = q.front().x, ty = q.front().y;
			map[tx][ty] = 0;
			q.pop();
		}
		q.push(snake( x,y ));
		map[x][y] = 2;
		if (cnt < l && ans == cmds[cnt].first) {
			switch (cmds[cnt].second) {
				case 'L':
					d = (d - 1 == -1 ? 3 : d - 1);
					break;
				case 'D':
					d = (d + 1 == 4 ? 0 : d + 1);
					break;
			}
			cnt++;
		}
	}
}
int main()
{
	io;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		map[x][y] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int x;
		char c;
		cin >> x >> c;
		cmds.push_back(make_pair( x,c ));
	}
	solve();
	cout << ans << '\n';
	return 0;
}