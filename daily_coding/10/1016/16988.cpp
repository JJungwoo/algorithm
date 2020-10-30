/*
[boj] 16988. Baaaaaaaaaduk2 (Easy)
https://www.acmicpc.net/problem/16988
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int dir[4][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
int N, M, answer;
int map[21][21];
bool check[21][21][21][21];
struct obj {
    int x, y;
    obj(int _x, int _y) : x(_x), y(_y) {}
};
vector<pair<int, int> > sel;
int bfs(int x, int y, bool visited[21][21]) {
    int ret = 1;
    bool fail = false;
    queue<obj> q;
    visited[x][y] = true;
    q.push(obj(x, y));
    while(!q.empty()) {
        obj cur = q.front(); q.pop();
        for(int i=0;i<4;i++) {
            int cx = cur.x + dir[i][0], cy = cur.y + dir[i][1];
            if(cx < 0 || cy < 0 || cx >= N || cy >= M) continue;
            if(map[cx][cy] == 0) {
                fail = true;
            }
        }
        for(int i=0;i<4;i++) {
            int mx = cur.x + dir[i][0], my = cur.y + dir[i][1];
            if(mx < 0 || my < 0 || mx >= N || my >= M) continue;
            if(visited[mx][my]) continue;
            if(map[mx][my] != 2) continue;
            visited[mx][my] = true;
            ret++;
            q.push(obj(mx, my));
        }
    }
    if(fail) 
        ret = 0;
    return ret;
}
int simul() {
    int ret = 0;
    bool visited[21][21];
    memset(visited, false, sizeof(visited));
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(map[i][j] == 2 && !visited[i][j]) {
                ret += bfs(i, j, visited);
            }
        }
    }
    return ret;
}
void print_map() {
    cout<<"print_map()\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout<<map[i][j]<<" ";
        }
        cout<<'\n';
    }
}
void dfs(int x, int y, int cnt) {
    if(cnt == 2) {
        //cout<<"x: "<<x<<" y: "<<y<<"\n";
        //print_map();
        check[sel[0].first][sel[0].second][sel[1].first][sel[1].second] = true;
        answer = max(answer, simul());
        return ; 
    }

    for(int i=x;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(map[i][j] == 0 && !check[x][y][i][j]) {
                map[i][j] = 1;
                sel.push_back(make_pair(i, j)); 
                dfs(i, j, cnt+1);
                sel.pop_back();
                map[i][j] = 0;
            }
        }
    }
}
void solve() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(map[i][j] == 0) {
                map[i][j] = 1;
                sel.push_back(make_pair(i, j));
                dfs(i, j, 1);
                sel.pop_back();
                map[i][j] = 0;
            }
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
        }
    }
    solve();   
    return 0;
}