/*
[boj] 13460. 구슬 탈출2 
https://www.acmicpc.net/problem/13460
*/
#include <iostream>
#include <queue>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };   // 시계 방향
int N, M;
char map[11][11];
bool visited[11][11][11][11];   // rx, ry, bx, by
int red[2], blue[2], endpoint[2];
struct obj {
    int rx, ry, bx, by, cnt;
    obj(int _rx, int _ry, int _bx, int _by, int _cnt) : 
    rx(_rx), ry(_ry), bx(_bx), by(_by), cnt(_cnt) {}
};
void move_ball(int &x, int &y, int d) {
    int mx = x + dir[d][0], my = y + dir[d][1];
    while(map[mx][my] != '#') {
        x = mx, y = my;
        if(map[x][y] == 'O') break;
        mx = x + dir[d][0], my = y + dir[d][1];
    }
}
void solve() {
    int answer = -1;
    queue<obj> q;
    visited[red[0]][red[1]][blue[0]][blue[1]] = true;
    q.push(obj(red[0], red[1], blue[0], blue[1], 0));
    while(!q.empty()) {
        obj cur = q.front(); q.pop();
        if(cur.cnt > 10) continue;
        if(cur.rx == endpoint[0] && cur.ry == endpoint[1] 
            && !(cur.bx == endpoint[0] && cur.by == endpoint[1])) {
            answer = cur.cnt;
            break;
        }
        for(int i=0;i<4;i++) {
            int rmx = cur.rx, rmy = cur.ry;
            int bmx = cur.bx, bmy = cur.by;
            move_ball(rmx, rmy, i);
            move_ball(bmx, bmy, i);
            if(bmx == endpoint[0] && bmy == endpoint[1]) continue;
            if(rmx == bmx && rmy == bmy) { 
                if(i == 0) {
                    if(cur.rx > cur.bx) rmx++;
                    else bmx++;
                }
                else if(i == 1) {
                    if(cur.ry > cur.by) bmy--;
                    else rmy--;
                }else if(i == 2) {
                    if(cur.rx > cur.bx) bmx--;
                    else rmx--;
                }
                else if(i == 3) {
                    if(cur.ry > cur.by) rmy++;
                    else bmy++;
                }
            }
            if(visited[rmx][rmy][bmx][bmy]) continue;
            visited[rmx][rmy][bmx][bmy] = true;
            q.push(obj(rmx, rmy, bmx, bmy, cur.cnt+1));
        }
    }
    cout<<answer<<"\n";
}
int main() 
{
    io;
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> map[i][j];
            if(map[i][j] == 'B')
                blue[0] = i, blue[1] = j;
            else if(map[i][j] == 'R') 
                red[0] = i, red[1] = j;
            else if(map[i][j] == 'O')
                endpoint[0] = i, endpoint[1] = j;
        }
    }
    solve();
    return 0;
}