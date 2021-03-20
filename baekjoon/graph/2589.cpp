/*
[boj] 2589. 보물섬
https://www.acmicpc.net/problem/2589
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int N, M, ans;
char field[51][51];
struct obj{
    int x, y, cnt;
};
void bfs(int x, int y) {
    bool visited[51][51];
    memset(visited, false, sizeof(visited));
    int local_ans = 0;
    queue<obj> q;
    visited[x][y] = true;
    q.push({x, y, 0});
    while(!q.empty()) {
        obj cur = q.front(); q.pop();
        local_ans = max(local_ans, cur.cnt);
        for(int i=0;i<4;i++) {
            int nx = cur.x + dir[i][0], ny = cur.y + dir[i][1];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(visited[nx][ny]) continue;
            if(field[nx][ny] == 'W') continue;
            visited[nx][ny] = true;
            q.push({nx, ny, cur.cnt+1});
        }
    }
    ans = max(ans, local_ans);
}
int main() 
{
    io;
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> field[i][j];
        }
    }
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(field[i][j] == 'L') {
                bfs(i, j);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
