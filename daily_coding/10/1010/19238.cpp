/*
[boj] 19238. 스타트 택시
https://www.acmicpc.net/problem/19238
*/
/*
가장 최단거리 승객을 먼저 탑승
거리가 같으면 가장 작은 행 번호 승객
가장 작은 번호가 여러명이면 열 번호가 가장 작은 작은 승객
택시와 승객이 같은 위치면 최단거리가 0
한 승객을 목적지로 이동시키면 그 승객을 태워 이동하면서 소모한 연료의 양이 두배 충전됨
승객을 목적지에 이동시키는 동시에 연료가 바닥나면 실패가 아니다.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, M, K;    // 맵 크기, 승객 수, 연료 양
pair<int, int> map[21][21];
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int car[2]; // 행, 열
bool cmp(pair<pair<int, int>, int> A, pair<pair<int, int>, int> B) {
    if(A.second ==  B.second) {
        if(A.first.first == B.first.first) return A.first.second < B.first.second;
        else return A.first.first < B.first.first;
    }
    else return A.second < B.second;
}
void print_map() {
    cout<<"print_map\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<map[i][j].first<<" ";
        }
        cout<<"\n";
    }
}
void find_passenger() {
    if(map[car[0]][car[1]].first > 1) // 승객이 바로 택시 위치에 있을 경우
        return ;
    int max_cnt = K;
    queue<pair<pair<int, int>, pair<int, int> > > q;
    vector<pair<pair<int, int>, int> > possible;
    q.push(make_pair(make_pair(car[0], car[1]), make_pair(K, 0)));
    bool visited[21][21];
    memset(visited, 0, sizeof(visited));
    visited[car[0]][car[1]] = true;
    while(!q.empty()) {
        int x = q.front().first.first, y = q.front().first.second;
        int cur_oil = q.front().second.first, cur_move = q.front().second.second;
        q.pop();
        if(map[x][y].first >= 2 && cur_oil > 0) {
            possible.push_back(make_pair(make_pair(x, y), cur_move));
        }   // 그만 승객 찾기
        if(cur_oil == 0) continue;

        for(int i=0;i<4;i++) {
            int mx = x + dir[i][0], my = y + dir[i][1];
            if(mx < 0 || my < 0 || mx >= N || my >= N) continue;
            if(map[mx][my].first == 1) continue;
            if(visited[mx][my]) continue;
            visited[mx][my] = true;
            q.push(make_pair(make_pair(mx, my), make_pair(cur_oil - 1, cur_move + 1)));
        }
    }
    if(possible.size() == 0) {
        K = -1;
    }else {
        sort(possible.begin(), possible.end(), cmp);
        car[0] = possible[0].first.first;
        car[1] = possible[0].first.second;
        K = K - possible[0].second;
    }
}
void go_goal() {
    int rest_oil;
    pair<int, int> last_location = make_pair(-1, -1);
    int stand = map[car[0]][car[1]].first;
    map[car[0]][car[1]].first = 0;
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(car[0], car[1]), K));
    bool visited[21][21];
    memset(visited, 0, sizeof(visited));
    visited[car[0]][car[1]] = true;
    while(!q.empty()) {
        int x = q.front().first.first, y = q.front().first.second;
        int cur_oil = q.front().second;
        q.pop();
        if(map[x][y].second == stand) {
            last_location.first = x;
            last_location.second = y;
            rest_oil = cur_oil;
            break;
        }   // 그만 승객 찾기
        else if(cur_oil <= 0) {
            K = -1;
            return;
        }

        for(int i=0;i<4;i++) {
            int mx = x + dir[i][0], my = y + dir[i][1];
            if(mx < 0 || my < 0 || mx >= N || my >= N) continue;
            if(map[mx][my].first == 1) continue;
            if(visited[mx][my]) continue;
            visited[mx][my] = true;
            q.push(make_pair(make_pair(mx, my), cur_oil - 1));
        }
    }
    if(last_location.first == -1)
        K = -1;
    else {
        car[0] = last_location.first;
        car[1] = last_location.second;
        map[car[0]][car[1]].second = 0;
        K = (K - rest_oil) * 2 + rest_oil;
        M--;
    }
}
void solve() {
    while(M >= 0) {
        find_passenger();
        if(K <= 0) break;
        go_goal();
        if(K <= 0) break;
    }
    if(K < 0) cout<<"-1\n";
    else cout<<K<<"\n";
}

int main() 
{
    io;
    cin >> N >> M >> K;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> map[i][j].first;
        }
    }
    cin >> car[0] >> car[1];
    car[0]--;
    car[1]--;
    
    for(int i=2;i<M+2;i++) {
        int sx, sy, dx, dy;
        cin >> sx >> sy >> dx >> dy;
        sx--;
        sy--;
        dx--;
        dy--;
        map[sx][sy].first = i;
        map[dx][dy].second = i;
    }
    solve();    
    return 0;
}