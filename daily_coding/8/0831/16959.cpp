/*
[boj] 16959. 체스판 여행 1
https://www.acmicpc.net/problem/16959
*/

#include <iostream>
#include <queue>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, ans;
int map[11][11];
bool visited[11][11][101][3];
int Ndir[8][2] = {
    {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}
};
int dir[2][4][2] = {
    { {-1, -1}, {-1, 1}, {1, 1}, {1, -1} },
    { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }
};
struct obj {    // type 0: 나이트, 1: 비숍, 2: 룩
    int x, y, cnt, type, num;
    obj(int _x, int _y, int _cnt, int _type, int _num) : x(_x), y(_y), cnt(_cnt), type(_type), num(_num) {}
};
bool operator < (const obj A, const obj B) {
    return A.cnt > B.cnt;
}
bool is_range(int x, int y){
    if(x < 0 || y < 0 || x >= N || y >= N) return false;
    return true;
}
void bfs(int x, int y) {
    priority_queue<obj> pq;
    pq.push(obj(x,y,0,0,1));
    pq.push(obj(x,y,0,1,1));
    pq.push(obj(x,y,0,2,1));
    visited[x][y][1][0] = true;
    visited[x][y][1][1] = true;
    visited[x][y][1][2] = true;
    
    while(!pq.empty()){
        obj cur = pq.top();
        pq.pop();

        if(map[cur.x][cur.y] == N*N && cur.num == N*N) {
            ans = cur.cnt;
            break;
        }
        switch(cur.type) {
            case 0: // 나이트
            {
                for(int i=0;i<8;i++) {
                    int mx = Ndir[i][0] + cur.x, my = Ndir[i][1] + cur.y;
                    int num = cur.num;
                    if(!is_range(mx, my)) continue;
                    if(map[mx][my] == num+1) num++;
                    if(visited[mx][my][num][cur.type]) continue;
                    visited[mx][my][num][cur.type] = true;
                    pq.push(obj(mx, my, cur.cnt + 1, 0, num));
                }
            }
            break;
            case 1: // 비숍
            {
                for(int i=0;i<4;i++) {
                    for(int j=1; ;j++) {
                        int mx = cur.x + dir[cur.type-1][i][0] * j, my = cur.y + dir[cur.type-1][i][1] * j;
                        int num = cur.num;
                        if(!is_range(mx, my)) break;
                        if(map[mx][my] == num+1) num++;
                        if(visited[mx][my][num][cur.type]) continue;
                        visited[mx][my][num][cur.type] = true;
                        pq.push(obj(mx, my, cur.cnt + 1, 1, num));
                    }
                }
            }
            break;
            case 2: // 룩
            {
                for(int i=0;i<4;i++) {
                    for(int j=1; ;j++) {
                        int mx = cur.x + dir[cur.type-1][i][0] * j, my = cur.y + dir[cur.type-1][i][1] * j;
                        int num = cur.num;
                        if(!is_range(mx, my)) break;
                        if(map[mx][my] == num+1) num++;
                        if(visited[mx][my][num][cur.type]) continue;
                        visited[mx][my][num][cur.type] = true;
                        pq.push(obj(mx, my, cur.cnt + 1, 2, num)); 
                    }
                }
            }
            break;
        }

        for(int i=0;i<3;i++) {
            if(visited[cur.x][cur.y][cur.num][i]) continue;
            visited[cur.x][cur.y][cur.num][i] = true;
            pq.push(obj(cur.x, cur.y, cur.cnt + 1, i, cur.num));
        }
    }
}
int main()
{
    io;
    int startx, starty;
    cin >> N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) {
                startx = i, starty = j;
            }
        }
    }
    bfs(startx, starty);
    cout << ans << "\n";
    return 0;
}
