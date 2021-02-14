/*
[boj] 17836. 공주님을 구해라!
https://www.acmicpc.net/problem/17836
*/
#include <bits/stdc++.h>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int n, m, t, ans = INT_MAX;
int arr[101][101];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
struct obj {
	int x, y, move;
};
inline int diff(int sx, int sy, int dx, int dy) {
	return abs(dx - sx) + abs(dy - sy);
}
void bfs() {
	int r1 = INT_MAX, r2 = INT_MAX;
	queue<obj> q;
	q.push({0,0,0});
	while(!q.empty()) {
		obj cur = q.front();q.pop();
		if(cur.x == n-1 && cur.y == m-1) {
			r1 = cur.move;
			break;
		}
		for(int i=0;i<4;i++) {
			int nx = cur.x + dir[i][0], ny = cur.y + dir[i][1];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m 
				|| arr[nx][ny] == -1 || arr[nx][ny] == 1)
				 continue;
			if(arr[nx][ny] == 2) {
				r2 = cur.move + diff(nx, ny, n-1, m-1) + 1;
			}else{
				q.push({nx, ny, cur.move+1});
			}
			arr[nx][ny] = -1;
		}
	}
	ans = min(r1, r2);
}
int main()
{
	io;
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	bfs();
	if(ans > t) cout<<"Fail\n";
	else cout<<ans<<"\n";

	return 0;
}