/*
[boj] 2146. 다리 만들기
https://www.acmicpc.net/problem/2146
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define LAND 1
#define MAX_INT 1e9
const int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int N, answer = MAX_INT;
int field[101][101];
bool visited[101][101];
struct obj {
    int x, y, cnt;
};
bool build_check(int x, int y) {
    for(int i=0;i<4;i++)
        if (field[x+dir[i][0]][y+dir[i][1]] != LAND) 
            return true;
    return false;
}
void land_setting(int x, int y, int set_num) {
    queue<obj> q;
    q.push({x, y, 0});
    field[x][y] = set_num;
    while(!q.empty()) {
        obj cur = q.front(); q.pop();
        for(int i=0;i<4;i++) {
            int nx = cur.x + dir[i][0], ny = cur.y + dir[i][1];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (field[nx][ny] != LAND) continue;
            field[nx][ny] = set_num;
            q.push({nx, ny, 0});
       }
    }
}
void build_bridge(int x, int y, int start_point) {
    memset(visited, false, sizeof(visited));
    queue<obj> q;
    q.push({x, y, 0});
    while(!q.empty()) {
        obj cur = q.front(); q.pop();
        if (field[cur.x][cur.y] != start_point && field[cur.x][cur.y] > LAND) {
            answer = min(answer, cur.cnt-1);
            break;
        }
        for(int i=0;i<4;i++) {
            int nx = cur.x + dir[i][0], ny = cur.y + dir[i][1];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (field[nx][ny] == start_point) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            q.push({nx, ny, cur.cnt+1});
        }
    }
}
int main() 
{
    io;
    cin >> N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> field[i][j];
        }
    }

    int set_count = LAND;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(field[i][j] == LAND) {
                land_setting(i, j, ++set_count);
            }
        }
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(field[i][j] > LAND && build_check(i, j)) {
                build_bridge(i, j, field[i][j]);
            }
        }
    }

    cout<<answer<<"\n";
    return 0;
}