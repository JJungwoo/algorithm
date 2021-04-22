/*
[boj] 4179. 불!
https://www.acmicpc.net/problem/4179
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define MAX_SIZE 1000 + 1
enum {
    USER, FIRE
};
const int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int R, C, answer;
char maze[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
bool checked[MAX_SIZE][MAX_SIZE][2];
vector<pair<int, int>> fire_pos;
pair<int, int> my;
struct obj {
    int x, y, cnt, type;
};
static inline bool range_check(int x, int y) {
    if (x < 0 || y < 0 || x >= R || y >= C) 
        return true;
    return false;
}
void bfs() {
    queue<obj> q;
    for(auto it : fire_pos) {
        q.push({it.first, it.second, 1, FIRE});
        visited[it.first][it.second] = 1;
        checked[it.first][it.second][FIRE] = true;
    }
    q.push({my.first, my.second, 1, USER});
    visited[my.first][my.second] = 1;
    checked[my.first][my.second][USER] = true;
    while (!q.empty()) {
        obj cur = q.front(); q.pop();

        for (int i=0; i<4; i++) {
            int nx = cur.x + dir[i][0], ny = cur.y + dir[i][1];
            if (range_check(nx, ny)) {
                if (cur.type == FIRE) continue;
                else {
                    cout << cur.cnt << "\n";
                    exit(0);
                } 
            }
            if (maze[nx][ny] == '#') continue;
            if (cur.cnt <= visited[nx][ny]) continue;
            if (checked[nx][ny][cur.type]) continue;
            checked[nx][ny][cur.type] = true;
            visited[nx][ny] = cur.cnt + 1;
            q.push({nx, ny, cur.cnt + 1, cur.type});
        }
    }
}
int main() 
{
    io;
    cin >> R >> C;
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'J') {
                my.first = i, my.second = j;
            } else if (maze[i][j] == 'F') {
                fire_pos.push_back({i, j});
            }
        }
    }
    bfs();
    cout << "IMPOSSIBLE\n";
    return 0;
}
