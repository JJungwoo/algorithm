/*
[boj] 19238. 스타트 택시 
https://www.acmicpc.net/problem/19238
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int N, M, K, curM, curC;
pair<int, int> map[21][21];
vector<pair<pair<int, int>, pair<int, int> > > customers;
int car[2];
void go_customer() {
    vector<pair<int, pair<int, int> > > v;
    bool visited[21][21];
    queue<pair<pair<int, int>, pair<int, int> > > q;
    memset(visited, false, sizeof(visited));
    visited[car[0]][car[1]] = true;
    q.push(make_pair(make_pair(car[0],car[1]), make_pair(0,0)));
    while(!q.empty()) {
        int x = q.front().first.first, y = q.front().first.second;
        int cnt = q.front().second.first;
        q.pop();
        if(map[x][y].first > 0) {
            v.push_back(make_pair(cnt, make_pair(x, y)));
        }
        for(int i=0;i<4;i++) {
            int mx = x + dir[i][0], my = y + dir[i][1];
            if(mx < 0 || my < 0 || mx >= N || my >= N) continue;
            if(visited[mx][my]) continue;
            if(map[mx][my].first == -1) continue;
            visited[mx][my] = true;
            q.push(make_pair(make_pair(mx,my), make_pair(cnt+1,0)));
        }
    }

    if(v.size() > 0) {
        sort(v.begin(), v.end());
        car[0] = v[0].second.first, car[1] = v[0].second.second;
        curC = map[car[0]][car[1]].first;
        map[car[0]][car[1]].first = 0;
        K = (K - v[0].first);
    }
    else K = -1;
}
void go_goal() {
    bool visited[21][21];
    queue<pair<pair<int, int>, pair<int, int> > > q;
    memset(visited, false, sizeof(visited));
    visited[car[0]][car[1]] = true;
    q.push(make_pair(make_pair(car[0],car[1]), make_pair(0,0)));
    while(!q.empty()) {
        int x = q.front().first.first, y = q.front().first.second;
        int cnt = q.front().second.first;
        q.pop();
        //if(map[customers[curC].second.first][customers[curC].second.second].first > 0) {
        if(x == customers[curC].second.first && y == customers[curC].second.second && K >= cnt) {
            car[0] = x, car[1] = y;
            K = (K - cnt) + (cnt * 2);
            map[car[0]][car[1]].second = 0;
            curM--;
            return ;
        }
        for(int i=0;i<4;i++) {
            int mx = x + dir[i][0], my = y + dir[i][1];
            if(mx < 0 || my < 0 || mx >= N || my >= N) continue;
            if(visited[mx][my]) continue;
            if(map[mx][my].first == -1) continue;
            visited[mx][my] = true;
            q.push(make_pair(make_pair(mx,my), make_pair(cnt+1,0)));
        }
    }

    K = -1;
}
int solve() {
    while(curM > 0) {
        go_customer();
        if(K < 0) return -1;
        go_goal();
        if(K < 0) return -1;
    }
    return K;
}
int main() 
{
    io;
    cin >> N >> M >> K;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> map[i][j].first;
            if(map[i][j].first == 1) map[i][j].first = -1;
        }
    }
    customers.push_back(make_pair(make_pair(-1,-1), make_pair(-1,-1)));
    cin >> car[0] >> car[1];
    car[0]--, car[1]--;
    for(int i=1;i<=M;i++) {
        int sx, sy, dx, dy;
        cin >> sx >> sy >> dx >> dy;
        sx--, sy--, dx--, dy--;
        map[sx][sy].first = i;
        map[dx][dy].second = i;
        customers.push_back(make_pair(make_pair(sx,sy), make_pair(dx,dy)));
    }
    curM = M;
    cout<< solve() <<"\n";
    return 0;
}