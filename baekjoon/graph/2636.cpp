/*
[boj] 2636. 치즈
https://www.acmicpc.net/problem/2636
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define CHEESE_VALUE 1
const int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int R, C;
int field[101][101];
bool visited[101][101];
vector<pair<int, int> > meltv;
inline static bool is_melt(int x, int y) {
    for (int i=0;i<4;i++) {
        if (field[x + dir[i][0]][y + dir[i][1]] != CHEESE_VALUE) {
            return true;
        }
    }
    return false;
}
int go_cheese_melt() {
    int ret = 0;
    for (auto it : meltv) {
        field[it.first][it.second] = 0;
        ret++;
    }
    meltv.clear();
    return ret;
}
pair<int, int> find_not_cheese() {
    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            if (field[i][j] != CHEESE_VALUE)
                return {i, j};
        }
    }
    return {0, 0};
}
bool find_melt_cheese_bfs() {
    auto it = find_not_cheese();
    queue<pair<int, int> > q;
    q.push({it.first, it.second});
    visited[it.first][it.second] = true;
    memset(visited, 0, sizeof(visited));
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(int i=0;i<4;i++) {
            int nx = cur.first + dir[i][0], ny = cur.second + dir[i][1];
            if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            if (field[nx][ny] == CHEESE_VALUE) {
                meltv.push_back({nx, ny});
            } else {
                q.push({nx, ny});
            }
        }
    }
    return (meltv.size() > 0 ? true : false);
}
pair<int, int> simul() {
    bool goloop = true;
    int loop = 0;
    int rest_cheese = 0;
    while(find_melt_cheese_bfs()) {
        rest_cheese = go_cheese_melt();
        loop++;
    }
    return {loop, rest_cheese};
}
int main() 
{
    io;
    cin >> R >> C;
    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            cin >> field[i][j];
        }
    }
    auto answer = simul();
    cout << answer.first << "\n" << answer.second << "\n";
    return 0;
}