/*
[boj] 17144. 미세먼지 안녕!
https://www.acmicpc.net/problem/17144
*/

#include <iostream>
#include <cstring>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };   // 시계 방향 
int ddir[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };    // 반 시계 방향
int R, C, T;
int map[51][51];
pair<int, int> air[2];

void copy_map(int tmp[51][51]) {
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            if(map[i][j] == -1) continue;
            map[i][j] = tmp[i][j];
        }
    } 
}
int spread(int x, int y, int tmp[51][51]) {
    int cnt = 0;
    for(int i=0;i<4;i++) {
        int mx = x + dir[i][0], my = y + dir[i][1];
        if(mx < 0 || my < 0 || mx >= R || my >= C) continue;
        if(map[mx][my] == -1) continue;
        tmp[mx][my] += (map[x][y] / 5);
        cnt++;
    }
    return cnt;
}
void wind(int x, int y, int tmp[51][51], bool wdir) {
    if(wdir) {  // 시계 방향
        int mx = x + dir[0][0], my = y + dir[0][1];
        for(int i=0;i<4;i++) {            
            while(true) {
                int tmx = mx + dir[i][0], tmy = my + dir[i][1];
                if(tmx < 0 || tmy < 0 || tmx >= R || tmy >= C || map[tmx][tmy] == -1) break;
                tmp[tmx][tmy] = map[mx][my];
                mx = tmx, my = tmy;
            }
        }
        tmp[x + dir[0][0]][y + dir[0][1]] = 0;
    }
    else {  // 반시계 방향 (역순)
        int mx = x + ddir[0][0], my = y + ddir[0][1];
        for(int i=0;i<4;i++) {            
            while(true) {
                int tmx = mx + ddir[i][0], tmy = my + ddir[i][1];
                if(tmx < 0 || tmy < 0 || tmx >= R || tmy >= C || map[tmx][tmy] == -1) break;
                tmp[tmx][tmy] = map[mx][my];
                mx = tmx, my = tmy;
            }
        }
        tmp[x + ddir[0][0]][y + ddir[0][1]] = 0;
    }
}
void simul() {
    int after_map[51][51];
    memset(after_map, 0, sizeof(after_map));
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            if(map[i][j] > 4) { // 5 이상부터 확산 가능하다.
                int ret = spread(i, j, after_map);
                map[i][j] = map[i][j] - ((map[i][j] / 5) * ret);
            }
        }
    }
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            if(map[i][j] == -1) continue;
            map[i][j] += after_map[i][j];
            after_map[i][j] = map[i][j];
        }
    }
    wind(air[0].first, air[0].second, after_map, false);
    wind(air[1].first, air[1].second, after_map, true);
    copy_map(after_map);
}
void solve() {
    int answer = 0;
    while(T--) {
        simul();
    }
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            if(map[i][j] > 0)
                answer += map[i][j];
        }
    }
    cout<<answer<<"\n";
}
int main() 
{
    io;
    cin >> R >> C >> T;
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            cin >> map[i][j];
            if(map[i][j] == -1) {
                if(air[0].first == 0)
                    air[0].first = i, air[0].second = j;
                else 
                    air[1].first = i, air[1].second = j;
            }
        }
    }
    solve();
    return 0;
}