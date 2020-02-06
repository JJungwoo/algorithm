/*
[BOJ] 14502. 연구소
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n,m,ans;
int map[8][8];
int map_copy[8][8];

int main()
{
	io;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
			map_copy[i][j] = map[i][j];
		}
	}

	

	return 0;
}

/*
int n, m, ans;
int map[8][8];
int map_copy[8][8];

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void reset(int (*map_des)[8], int (*map_src)[8]) {
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			map_des[i][j] = map_src[i][j];
		}
	}
}

void bfs(){
	int virus_map[8][8];
	reset(virus_map, map_copy);
	queue<pair<int, int> > qp;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(virus_map[i][j] == 2){
				qp.push(make_pair(i, j));
			}
		}
	}
	while(!qp.empty()){		// virus 
		int x = qp.front().first;
		int y = qp.front().second;
		qp.pop();
		for(int i=0;i<4;i++){
			int mx = x + dir[i][0], my = y + dir[i][1];
			if(mx < 0 || my < 0 || mx >= n || my >= m) continue;
			if(virus_map[mx][my] == 0){
				virus_map[mx][my] = 2;
				qp.push(make_pair(mx, my));
			}
		}
	}
	int res = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(virus_map[i][j] == 0){
				res+1;
			}
		}
	}
	ans = max(ans, res);
}

void solve(int cnt){	// same n&m
	if(cnt == 3){
		bfs();
		return;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map_copy[i][j] == 0) {	// can wall setting
				map_copy[i][j] = 1;
				solve(cnt+1);
				map_copy[i][j] = 0;
			}
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
		}
	}
    
	for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
            if(map[i][j] == 0){		// wall setting
				reset(map_copy, map);
				map_copy[i][j] = 1;
				solve(1);
				map_copy[i][j] = 0;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
*/

/*
int n, m, safezone = -3, ans = 1e9;
int map[9][9];
bool visited[9][9];

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct virus{
    int x,y;
    virus(int _x, int _y): x(_x), y(_y){}
};

vector<virus> vv;

int dfs(int x, int y){
    int res = 1;
    visited[x][y] = true;
    for(int i=0;i<4;i++){
        int mx = x+dir[i][0], my = y+dir[i][1];
        if(mx < 0 || mx >= n || my < 0 || my >= m) continue;
        if(visited[mx][my] || map[mx][my]) continue;
        res += dfs(mx,my);
    }
    return res;
}

void solve(int wall, int x, int y){
    if(wall == 3){
        int cnt = 0;
        memset(visited, 0, sizeof(visited));
        int len = vv.size();
        for(int k=0;k<len;k++){
            cnt += dfs(vv[k].x, vv[k].y);
        }
        if(ans > cnt) ans = cnt;
        return;
    }
    for(int i=0;i<n;i++){       // 벽을 랜덤으로 세우는 부분.
        for(int j=0;j<m;j++){
            if(visited[i][j] == 0){
                visited[i][j] = true;
                solve(wall+1, i, j+1);
                visited[i][j] = false;
            }
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
            if(map[i][j] != 1) safezone++;
            if(map[i][j] == 2){
                virus v(i,j);
                vv.push_back(v);
            }
        }
    }
    
    solve(0,0,0);
    cout<<safezone<<","<<ans<<"\n";
    cout<<safezone-ans<<"\n";
    return 0;
}
*/
