/*
[boj] 19238. 스타트 택시 
https://www.acmicpc.net/problem/19238
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int N, M, curM, stand;
long long K;
struct road{
    int start, end;
};
road map[21][21];
int car[2];
struct customer {
    int sx, sy, dx, dy;
    customer(int _sx, int _sy, int _dx, int _dy) : sx(_sx), sy(_sy), dx(_dx), dy(_dy) {}
};
vector<customer> v;
struct drive {
    int x, y, fuel, dist; // 좌표, 남은 연료, 이동 거리
    drive(int _x, int _y, int _fuel, int _dist) : x(_x), y(_y), fuel(_fuel), dist(_dist) {}
};

struct obj {
    int x, y, dist;
    obj(int _x, int _y, int _dist) : x(_x), y(_y), dist(_dist) {} 
};
bool cmp(obj A, obj B) {
    if(A.dist == B.dist) {
        if(A.x == B.x) return A.y < B.y;
        else return A.x < B.x;
    }
    else return A.dist < B.dist;
}

void print_map() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout<<map[i][j].start<<" ";
        }
        cout<<"\n";
    }
}
void find_customer() {
    vector<obj> pre_customers;
    bool visited[21][21];
    memset(visited, false, sizeof(visited));
    visited[car[0]][car[1]] = true;
    queue<drive> q;
    q.push(drive(car[0], car[1], K, 0));
    while(!q.empty()) {
        int x = q.front().x, y = q.front().y;
        int fuel = q.front().fuel, dist = q.front().dist;
        q.pop();
        if(fuel == 0) continue;
        if(v[map[x][y].start].sx == x && v[map[x][y].start].sy == y) {
            pre_customers.push_back(obj(x,y,dist));
        }
        for(int i=0;i<4;i++) {
            int mx = x + dir[i][0], my = y + dir[i][1];
            if(mx < 0 || my < 0 || mx >= N || my >= N) continue;
            if(map[mx][my].start == -1) continue;
            if(visited[mx][my]) continue;
            visited[mx][my] = true;
            q.push(drive(mx, my, fuel-1, dist+1));
        }
    }

    if(pre_customers.size() != 0) {
        sort(pre_customers.begin(), pre_customers.end(), cmp);
        car[0] = pre_customers[0].x;
        car[1] = pre_customers[0].y;
        K = K - pre_customers[0].dist;
        stand = map[car[0]][car[1]].start;
        map[car[0]][car[1]].start = 0;
    }
    else{
        K = -1;
    }
}

void find_end() {
    bool visited[21][21], end = false;;
    memset(visited, false, sizeof(visited));
    visited[car[0]][car[1]] = true;
    queue<drive> q;
    q.push(drive(car[0], car[1], K, 0));
    while(!q.empty()) {
        int x = q.front().x, y = q.front().y;
        int fuel = q.front().fuel, dist = q.front().dist;
        q.pop();
        if(v[stand].dx == x && v[stand].dy == y) {
            car[0] = x;
            car[1] = y;
            map[x][y].end = 0;
            K = fuel + (dist * 2);
            curM--;
            end = true;
            break;
        }
        if(fuel == 0) {
            K = -1;
            return;
        }
        for(int i=0;i<4;i++) {
            int mx = x + dir[i][0], my = y + dir[i][1];
            if(mx < 0 || my < 0 || mx >= N || my >= N) continue;
            if(map[mx][my].start == -1) continue;
            if(visited[mx][my]) continue;
            visited[mx][my] = true;
            q.push(drive(mx, my, fuel-1, dist+1));
        }
    }
    if(end == false) K = -1;
}

void solve() {
    while(curM > 0) {
        find_customer();
        if(K < 0) break;
        find_end();
        if(K < 0) break;
    }
    if(K < 0) K = -1;
    cout << K << "\n";
}
int main() 
{
    io;
    cin >> N >> M >> K;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> map[i][j].start;
            if(map[i][j].start == 1) map[i][j].start = -1;
        }
    }
    cin >> car[0] >> car[1];
    car[0]--, car[1]--;
    v.resize(M+1, customer(0,0,0,0));
    for(int i=1;i<=M;i++) {
        cin >> v[i].sx >> v[i].sy >> v[i].dx >> v[i].dy;
        v[i].sx--, v[i].sy--, v[i].dx--, v[i].dy--;
        map[v[i].sx][v[i].sy].start = i;
        map[v[i].dx][v[i].dy].end = i;
    }
    curM = M;
    solve();

    return 0;
}