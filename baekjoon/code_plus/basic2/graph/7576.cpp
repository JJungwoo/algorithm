/*
[BOJ] 7576. 토마토
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int dir[4][2] = {{-1,0}, {1,0}, {0, -1}, {0, 1}};
int n,m,ans;
int map[1001][1001];
queue<pair<int, int> > qpos;

void bfs()
{
	while(!qpos.empty()){
		pair<int, int> tmp = qpos.front();
		//cout<<tmp.first<<","<<tmp.second<<"\n";
		qpos.pop();
		for(int i=0;i<4;i++){
			int mx = tmp.first + dir[i][0], my = tmp.second + dir[i][1];
			if(mx < 0 || mx >= n || my < 0 || my >= m) continue;
			if(map[mx][my] || map[mx][my] == -1) continue;
			map[mx][my] = map[tmp.first][tmp.second] + 1;
			//cout<<map[mx][my]<<","<<cnt<<","<<mx<<","<<my<<"\n";
			qpos.push(make_pair(mx, my));
		}
	}
}

int main()
{
	io;
	cin>>m>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
			if(map[i][j] == 1){
				qpos.push(make_pair(i,j));
			}
		}
	}
	bfs();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!map[i][j]) {
				cout<<"-1\n";
				return 0;
			}
			if(ans < map[i][j]) ans = map[i][j];
		}
	}
	cout<<ans-1;

	return 0;
}
