/*
[boj] 17144. 미세먼지 안녕! 
https://www.acmicpc.net/problem/17144
*/

#include <iostream>
#include <cstring>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };   // 오른쪽에서부터 시계방향
int ddir[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };    // 오른쪽에서부터 반시계방향
int R, C, T;
int map[51][51], copymap[51][51];
pair<int, int> air[2];
void spread() {
    memset(copymap, 0, sizeof(copymap));
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            if(map[i][j] == -1 && map[i][j] < 5) continue;
            int cnt = 0, spread_val = map[i][j] / 5;
            for(int d=0;d<4;d++) {
                int mx = i + dir[d][0], my = j + dir[d][1];
                if(mx < 0 || my < 0 || mx >= R || my >= C) continue;
                if(map[mx][my] == -1) continue;
                copymap[mx][my] += spread_val; 
                cnt++;
            }
            map[i][j] = map[i][j] - (spread_val * cnt);
        }
    }
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            map[i][j] += copymap[i][j];
        }
    }
}
void move_dust(int x, int y, bool check) {
    
    if(check) { // 시계 방향
        y++;
        for(int i=0;i<4;i++) {
            int mx = x + dir[i][0], my = y + dir[i][1];
            while(true) {
                if(mx < 0 || my < 0 || mx >= R || my >= C || map[mx][my] == -1) break;
                copymap[mx][my] = map[x][y];
                x = mx, y = my;
                mx = x + dir[i][0], my = y + dir[i][1];
            }
        }
    }else{  // 반시계 방향
        y++;
        for(int i=0;i<4;i++) {
            int mx = x + ddir[i][0], my = y + ddir[i][1];
            while(true) {
                if(mx < 0 || my < 0 || mx >= R || my >= C || map[mx][my] == -1) break;
                copymap[mx][my] = map[x][y];
                x = mx, y = my;
                mx = x + ddir[i][0], my = y + ddir[i][1];
            }
        }
    }
}
void wind() {
    memset(copymap, 0, sizeof(copymap));

    move_dust(air[0].first, air[0].second, false);
    move_dust(air[1].first, air[1].second, true);

    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            if( (i == 0 || j == 0 || i == air[0].first || i == air[1].first
            || i == R-1 || j == C-1) && map[i][j] != -1 )
                map[i][j] = copymap[i][j];
    
}
void simul() {
    spread();
    wind();
}
int sum_map() {
    int ret = 0;
    for(int i=0;i<R;i++) 
        for(int j=0;j<C;j++)
            if(map[i][j] > 0)
                ret += map[i][j];
    return ret;
}
void solve() {
    int answer = 0;
    while(T--) {
        simul();
    }
    answer = sum_map();
    cout << answer << "\n";
}
int main() 
{
    io;
    cin >> R >> C >> T;
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            cin >> map[i][j];
            if(map[i][j] == -1 && air[0].first == 0) {
                air[0].first = i, air[0].second = j;
            }else if(map[i][j] == -1) {
                air[1].first = i, air[1].second = j;
            }
        }
    }
    solve();
    return 0;
}