/*
[BOJ] 2206. 벽 부수고 이동하기
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int MAX = 987654321;
int n,m,ans = MAX;
int map[1001][1001];
int dir[4][2] = {{0,-1}, {0, 1}, {-1,0}, {1, 0}};
bool visited[1001][1001];

void bfs()
{
	queue<pair<pair<int, int>, pair<int, int> > > qp;	// x, y, smash, cnt
	qp.push(make_pair(make_pair(0,0),make_pair(0,1)));
	//visited[0][0] = true;
	while(!qp.empty()){
		int tx = qp.front().first.first, ty = qp.front().first.second;
		int smash = qp.front().second.first, cnt = qp.front().second.second;
		qp.pop();
		if(tx == n-1 && ty == m-1){
			ans = min(ans, cnt);
		}
		for(int i=0;i<4;i++){
			int mx = tx + dir[i][0], my = ty + dir[i][1];
			if(mx < 0 || my < 0 || mx >= n || my >= m) continue;
			if(smash && map[mx][my]) continue;
			if(visited[mx][my]) continue;
			if(map[mx][my] == 1 && smash == 0){
				qp.push(make_pair(make_pair(mx,my), make_pair(smash+1,cnt+1)));
				visited[mx][my] = true;
			}else {
				qp.push(make_pair(make_pair(mx,my), make_pair(smash,cnt+1)));	
				visited[mx][my] = true;
			}
		}
	}
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d", &map[i][j]);
		}
	}

	bfs();
	if(MAX == ans) cout<<"-1\n";
	else cout<<ans<<"\n";

	return 0;
}
