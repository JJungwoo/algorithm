/*
[boj] 16236. 아기 상어 
https://www.acmicpc.net/problem/16236
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int N;
// 맵정보, 상어 위치, 현재 크기와 먹은 수와 이동거리
int map[21][21], shark[2], size_eat_move[3];
struct movement{
    int x, y, dist;
    movement(int _x, int _y, int _dist) : x(_x), y(_y), dist(_dist) {}
};
bool cmp(movement A, movement B) {
    if(A.dist == B.dist) {
        if(A.x == B.x) return A.y < B.y;
        else return A.x < B.x;
    }
    else return A.dist < B.dist;
}
bool simul() {
    bool visited[21][21];
    vector<movement> eat_fishs;
    queue<movement> q;
    memset(visited, false, sizeof(visited));
    visited[shark[0]][shark[1]] = true;
    q.push(movement(shark[0], shark[1], 0));
    
    while(!q.empty()) {
        movement cur = q.front(); q.pop();
        if(map[cur.x][cur.y] != 0 && map[cur.x][cur.y] < size_eat_move[0]) {
            eat_fishs.push_back(movement(cur.x, cur.y, cur.dist));
        }
        for(int i=0;i<4;i++) {
            int mx = cur.x + dir[i][0], my = cur.y + dir[i][1];
            if(mx < 0 || my < 0 || mx >= N || my >= N) continue;
            if(map[mx][my] > size_eat_move[0]) continue;
            if(visited[mx][my]) continue;
            visited[mx][my] = true;
            q.push(movement(mx, my, cur.dist+1));
        }
    }

    if(eat_fishs.size() > 0) {
        sort(eat_fishs.begin(), eat_fishs.end(), cmp);
        int x = eat_fishs[0].x, y = eat_fishs[0].y;
        map[x][y] = 0;
        shark[0] = x, shark[1] = y;
        size_eat_move[1]++;
        if(size_eat_move[0] == size_eat_move[1]) {
            size_eat_move[0]++;
            size_eat_move[1] = 0;
        }
        size_eat_move[2] += eat_fishs[0].dist;
        return true;
    }
    return false;
}
void solve() {
    int answer = 0;
    while(simul()) 
        ;
    answer = size_eat_move[2];
    cout << answer << "\n";
}
int main() 
{
    io;
    size_eat_move[0] = 2;
    cin >> N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> map[i][j];
            if(map[i][j] == 9) {
                shark[0] = i, shark[1] = j;
                map[i][j] = 0;
            }
        }
    }
    solve();
    return 0;
}