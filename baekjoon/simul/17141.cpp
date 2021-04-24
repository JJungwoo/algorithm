/*
[boj] 17141. 연구소 2
https://www.acmicpc.net/problem/17141
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define MAX_INT 2500
const int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int N, M, answer = MAX_INT, zeroCnt;
int field[51][51];
bool visited[10], tmp_field[51][51];
vector<pair<int, int>> virus, start_pos;
struct obj {
    int x, y, cnt;
};
bool check_field() {
    int cnt = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if (tmp_field[i][j]) 
                cnt++;
        }
    }
    return (cnt - virus.size() == zeroCnt ? true : false);
}
void bfs() {
    queue<obj> q;
    memset(tmp_field, 0, sizeof(tmp_field));
    for(auto it : start_pos) {
        q.push({it.first, it.second, 0});
        tmp_field[it.first][it.second] = true;
    }
    int max_cnt = 0;
    while(!q.empty()) {
        obj cur = q.front(); q.pop();
        max_cnt = max(max_cnt, cur.cnt);
        for(int i=0;i<4;i++) {
            int nx = cur.x + dir[i][0], ny = cur.y + dir[i][1];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (field[nx][ny] == 1) continue;
            if (tmp_field[nx][ny]) continue;
            tmp_field[nx][ny] = true;
            q.push({nx, ny, cur.cnt+1});
        }
    }
    if (check_field()) {
        answer = min(answer, max_cnt);
    }
}
void dfs(int idx, int cnt) {
    if (cnt == M) {
        bfs();
        return ;
    }

    for(int i=idx;i<virus.size();i++) {
        if (visited[i]) continue;
        visited[i] = true;
        start_pos.push_back(virus[i]);
        dfs(i, cnt+1);
        start_pos.pop_back();
        visited[i] = false;
    }
}
int main() {
    io;
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> field[i][j];
            if (field[i][j] == 2) {
                virus.push_back({i, j});
            } else if (field[i][j] == 0) {
                zeroCnt++;
            }
        }
    }
    dfs(0, 0);
    cout << (answer == MAX_INT ? -1 : answer) << "\n";
    return 0;
}