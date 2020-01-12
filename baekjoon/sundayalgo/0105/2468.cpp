/*
[BOJ] 2468. 안전 영역
*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, szone, ans;
int map[101][101];
bool visited[101][101];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

void dfs(int x, int y, int h){
    if(visited[x][y]) return;
    visited[x][y] = true;
    for(int i=0;i<4;i++){
        int mx = x + dir[i][0], my = y + dir[i][1];
        if(mx < 0 || my < 0 || mx >= n || my >= n) continue;
        if(map[mx][my] <= h) continue;
        if(visited[mx][my]) continue;
        dfs(mx,my,h);
    }
}

int main()
{
    io;     
    cin>>n;
    for(int i=0;i<n;i++) 
        for(int j=0;j<n;j++) cin>>map[i][j];
    
    for(int h=0;h<=100;h++){
        szone = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(map[i][j] > h && !visited[i][j]){
                    dfs(i,j,h);
                    szone++;
                }
            }
        }
        memset(visited, 0, sizeof(visited));
        if(szone > ans) ans = szone;
    }
    if(ans == 0) cout<<"1\n";
    else cout<<ans<<"\n";

    return 0;
}