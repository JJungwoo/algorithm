/*
[boj] 2615. 오목 
https://www.acmicpc.net/problem/2615
*/
#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define MAX 19
int dir[4][2] = {
    {-1, 1}, {0, 1}, {1, 0}, {1, 1}
};
int map[21][21];
void dfs(int sx, int sy, int x, int y, int d, int cnt) {
    if(cnt > 4) return;
    if(cnt == 4) {
        bool check = false, dcheck = false;
        dcheck = true;
        int mx = x + dir[d][0], my = y + dir[d][1];
        int dmx = sx - dir[d][0], dmy = sy - dir[d][1];
        if(dmx < 0 || dmy < 0 || dmx >= MAX || dmy >= MAX) {
            dcheck = true;
        }else{
            if(map[dmx][dmy] == map[x][y]) dcheck = false;
            else dcheck = true;
        }
        if(mx < 0 || my < 0 || mx >= MAX || my >= MAX) {
            check = true;
        }else{
            if(map[mx][my] == map[x][y]) check = false;
            else check = true;
        }
        if(check && dcheck) {
            cout<<map[x][y]<<"\n";
            cout<<sx+1<<" "<<sy+1<<"\n";            
            exit(0);
        }
        return ;
    }

    int mx = x + dir[d][0], my = y + dir[d][1];
    if(mx >= 0 && my >= 0 && mx < MAX && my < MAX) {
        if(map[mx][my] == map[x][y])
            dfs(sx, sy, mx, my, d, cnt+1);
    } 
}
void solve() {
    for(int i=0;i<MAX;i++) {
        for(int j=0;j<MAX;j++) {
            if(map[i][j] == 0) continue;
            int tmp = map[i][j];
            for(int d=0;d<4;d++) {
                int mx = i + dir[d][0], my = j + dir[d][1];
                if(mx < 0 || my < 0 || mx >= MAX || my >= MAX) continue;
                if(tmp == map[mx][my]) {
                    dfs(i, j, mx, my, d, 1);
                }
            }
        }
    }
    cout<<"0\n";
}
int main() 
{
    io;
    for(int i=0;i<MAX;i++) {
        for(int j=0;j<MAX;j++) {
            cin >> map[i][j];
        }
    }
    solve();
    return 0;
}