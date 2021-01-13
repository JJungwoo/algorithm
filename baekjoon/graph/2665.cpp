/*
[boj] 2665. 미로 만들기
https://www.acmicpc.net/problem/2665
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int INF = 1e9;
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int N;
int room[51][51], dist[51][51];
struct pos {
    int x, y;
};
void solve() {
    queue<pos> q;
    dist[0][0] = 0;
    q.push({0, 0});
    while(!q.empty()) {
        pos cur = q.front(); q.pop();
        for(int i=0;i<4;i++) {
            int nx = cur.x + dir[i][0], ny = cur.y + dir[i][1];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(room[nx][ny] == 1 && dist[nx][ny] > dist[cur.x][cur.y]) {
                dist[nx][ny] = dist[cur.x][cur.y];
                q.push({nx, ny});
            } else if(room[nx][ny] == 0 && dist[nx][ny] > dist[cur.x][cur.y] + 1) {
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                q.push({nx, ny});
            }
        }
    }
}
int main() {
    cin >> N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            scanf("%1d", &room[i][j]);
            dist[i][j] = INF;
        }
    }
    solve();
    printf("%d\n", dist[N-1][N-1]);
    return 0;
}