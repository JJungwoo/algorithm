/*
[BOJ] 10026. 적록색약
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
char map[101][100];
bool visited[101][101];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int cnt;

void bfs(int x, int y, bool c){
    queue< pair<int, int> > q;
    q.push(make_pair(x,y));
    visited[x][y] = true;
    while(!q.empty()){
        int mx = q.front().first, my = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int dx = mx + dir[i][0], dy = my + dir[i][1];
            if(dx < 0 || dy < 0 || dx >= n || dy >= n) continue;
            if(visited[dx][dy]) continue;
            if(c) {
                if(map[x][y] == 'B' && (map[dx][dy] == 'R' || map[dx][dy] == 'G')) continue;
                else if(map[x][y] != 'B' && map[dx][dy] == 'B') continue;
            }else if(!c && map[x][y] != map[dx][dy]) continue;
            visited[dx][dy] = true;
            q.push(make_pair(dx,dy));
        }
    }
}

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                //cout<<map[i][j]<<":"<<i<<","<<j<<"\n";
                cnt += 1;
                bfs(i,j,false);
            }
        }
    }
    cout<<cnt<<" ";
    cnt = 0;
    memset(visited, 0, sizeof(visited));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                //cout<<map[i][j]<<":"<<i<<","<<j<<"\n";
                cnt += 1;
                bfs(i,j,true);
            }
        }
    }
    cout<<cnt<<"\n";
    return 0;
}