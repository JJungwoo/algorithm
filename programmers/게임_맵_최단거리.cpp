/*
[programmers] 찾아라 프로그래밍 마에스터 게임 맵 최단거리
https://programmers.co.kr/learn/courses/30/lessons/1844
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX_INT 1e9
const int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
struct obj {
    int x, y;
};
int n, m;
int dist[100][100];
int bfs(vector<vector<int> > &maps) {
    queue<obj> q;
    q.push({0, 0});
    dist[0][0] = 1;
    while(!q.empty()) {
        obj cur = q.front(); q.pop();
        if (cur.x == n - 1 && cur.y == m - 1) {
            return dist[cur.x][cur.y];
        }
        for(int i=0;i<4;i++) {
            int nx = cur.x + dir[i][0], ny = cur.y + dir[i][1];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (maps[nx][ny] == 0) continue;
            if (dist[nx][ny] > dist[cur.x][cur.y] + 1) {
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int solution(vector<vector<int> > maps)
{
    n = maps.size();
    m = maps[0].size();
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            dist[i][j] = 1e9;
        }
    }
    int answer = bfs(maps);
    return answer;
}
