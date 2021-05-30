/*
[boj] 16973. 직사각형 탈출
https://www.acmicpc.net/problem/16973
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int N, M;
int H, W, SR, SC, FR, FC;
int board[1001][1001];
bool visited[1001][1001];
struct obj {
    int x1, y1, x2, y2, cnt;
};
inline bool bound_check(int x1, int y1, int x2, int y2, int d) {
    switch(d) {
        case 0:
            while(y1 <= y2) {
                if (board[x2][y1] == 1) return true; y1++;
            }
        break;
        case 1:
            while(y1 <= y2) {
                if (board[x1][y1] == 1) return true; y1++;
            }
        break;
        case 2:
            while(x1 <= x2) {
                if (board[x1][y2] == 1) return true; x1++;
            }
        break;
        case 3:
            while(x1 <= x2) {
                if (board[x1][y1] == 1) return true; x1++;
            }
        break;
    }
    return false;
}
int bfs() {
    queue<obj> q;
    q.push({SR, SC, SR + H - 1, SC + W - 1, 0});
    visited[SR][SC] = true;
    while(!q.empty()) {
        obj cur = q.front(); q.pop();
        if (cur.x1 == FR && cur.y1 == FC &&
            cur.x2 == FR + H - 1 && cur.y2 == FC + W - 1)
            return cur.cnt;
        for(int i=0;i<4;i++) {
            int nx1 = cur.x1 + dir[i][0], ny1 = cur.y1 + dir[i][1];
            int nx2 = cur.x2 + dir[i][0], ny2 = cur.y2 + dir[i][1];
            if (nx1 < 0 || ny1 < 0 || nx2 < 0 || ny2 < 0 ||
                nx1 >= N || ny1 >= M || nx2 >= N || ny2 >= M) continue;
            if (visited[nx1][ny1]) continue;
            if (bound_check(nx1, ny1, nx2, ny2, i)) continue;
            visited[nx1][ny1] = true;
            q.push({nx1, ny1, nx2, ny2, cur.cnt + 1});
        }
    }
    return -1;
}
int main() 
{
    io;
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> board[i][j];
        }
    }
    cin >> H >> W >> SR >> SC >> FR >> FC;
    SR--, SC--, FR--, FC--;
    cout<<bfs()<<"\n";
    return 0;
}