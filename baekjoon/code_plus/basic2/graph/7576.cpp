/*
[BOJ] 7576. 토마토
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

typedef struct{
	int x, y;
}pos;

int xm[4] = {0,0,0,0};
int ym[4] = {0,0,0,0};
int n,m;
int map[1001][1001];
queue<pos> qpos;

void bfs()
{
	while(!qpos.empty()){
		pos tmp = qpos.front();
		qpos.pop();
		for(int i=0;i<4;i++){
			int k = map[tmp.x][tmp.y];
			
		}
	}
}

int main()
{
	io;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
			if(map[i][j] == 1)
				qpos.push({i, j});
		}
	}
	bfs();
	

	return 0;
}
