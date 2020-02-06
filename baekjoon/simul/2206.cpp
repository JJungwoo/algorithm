/*
[BOJ] 2206. 벽 부수고 이동하기
visited 체크를 왔던 공간이 아닌 벽을 부셨는지 체크를 할 때 사용하여 품; 생각지 못함;;
다시 풀어야겠다. 
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int MAX = 987654321;
int n,m,ans = -1;
int map[1001][1001];
int dir[4][2] = {{0,-1}, {0, 1}, {-1,0}, {1, 0}};
bool visited[1001][1001][2];

int bfs()
{
	queue<pair<pair<int, int>, pair<int, int> > > qp;	// x, y, smash, cnt
	qp.push(make_pair(make_pair(0,0),make_pair(0,1)));
	visited[0][0][0] = true;
	while(!qp.empty()){
		int tx = qp.front().first.first, ty = qp.front().first.second;
		int smash = qp.front().second.first, cnt = qp.front().second.second;
		qp.pop();
		if(tx == n-1 && ty == m-1){
			return cnt;
		}
		for(int i=0;i<4;i++){
			int mx = tx + dir[i][0], my = ty + dir[i][1];
			if(mx < 0 || my < 0 || mx >= n || my >= m) continue;
			if(smash && map[mx][my]) continue;
			if(map[mx][my] == 1 && smash == 0){
				qp.push(make_pair(make_pair(mx,my), make_pair(smash+1,cnt+1)));
				visited[mx][my][smash+1] = true;
			} else if(map[mx][my] == 0 && visited[mx][my][smash] == false){
				qp.push(make_pair(make_pair(mx,my), make_pair(smash,cnt+1)));	
				visited[mx][my][smash] = true;
			}
		}
	}
	return -1;
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%1d", &map[i][j]);
		}
	}

	printf("%d\n", bfs());
	return 0;
}
