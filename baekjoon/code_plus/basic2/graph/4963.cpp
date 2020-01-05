/*
[BOJ] 4963. 섬의 개수
*/
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int dir[8][2] = \
{{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
int w, h, ans;
int map[51][51];
int visited[51][51];
queue<pair<int, int> > q;

void bfs(int x, int y)
{
    q.push(make_pair(x,y));
    while(!q.empty()){
        int tx = q.front().first, ty = q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int mx = tx + dir[i][0];
            int my = ty + dir[i][1];

            //cout<<mx<<","<<my<<"\n";
            if(mx < 0 || mx >= h || my < 0 || my >= w) continue;
            if(map[mx][my] == 0) continue;
            if(visited[mx][my]) continue;
            visited[mx][my] = true;
            q.push(make_pair(mx,my));
        }
    }
}

int main()
{
    io;
    while(1){
        cin>>w>>h;
        if(w == 0 && h == 0) return 0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>map[i][j];
            }
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(!visited[i][j] && map[i][j] == 1){
                    ans++;
                    visited[i][j] = true;
                    bfs(i, j);
                }
            }
        }
        cout<<ans<<"\n";
        ans = 0;
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
    }
    
    
    return 0;
}