/*
[BOJ] 14502. 연구소
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

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
    for(int i=x;i<n;i++){       // 벽을 랜덤으로 세우는 부분.
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