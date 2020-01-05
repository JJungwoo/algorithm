/*
[BOJ] 16929. Two Dots
점 k개의 사이클 정의
- 모든 k개의 점은 서로 다르다.
- k는 4보다 크거나 같다.
- 모든 점의 색은 같다.
- 모든 점들은 인접한 거리에 있다.
처음 위치는 방문 체크를 하면 안된다. 다시 돌아와야 하기 때문에..
dfs 재귀 전과 후에 방문 체크 온오프를 해줘야 한다. 
재귀 전과 후에 방문 체크 온오프는 다시 돌아오기 위해서 꼭 필요하다!!.
*/
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n,m,check;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char map[50][50];
bool visited[50][50];

void dfs(int x, int y, int sx, int sy, int cnt){
    if(cnt >= 4 && x == sx && y == sy) {
        check = 1;
        return;
    }
    for(int i=0;i<4;i++){
        int mx = x + dir[i][0], my = y + dir[i][1];
        if(mx < 0 || my < 0 || mx >= n || my >= m) continue;
        if(visited[mx][my]) continue;
        if(map[mx][my] != map[sx][sy]) continue;
        //if(cnt < 4 && mx == sx && my == sy) continue; // ??
        //cout<<mx<<","<<my<<","<<cnt<<"\n";
        visited[mx][my] = true;
        dfs(mx, my, sx, sy, cnt + 1);
        visited[mx][my] = false;    // ??
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
            memset(visited, 0, sizeof(visited));
            if(!visited[i][j]){
                dfs(i, j, i, j, 0);
            }
            if(check){
                cout<<"Yes\n";
                return 0;
            }
        }
    }
    cout<<"No\n";
    return 0;
}