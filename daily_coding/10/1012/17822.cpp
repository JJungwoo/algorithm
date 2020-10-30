/*
[boj] 17822. 원판 돌리기 
https://www.acmicpc.net/problem/17822
*/

#include <iostream>
#include <vector>
#include <cmath>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, M, T;
int map[51][51];
struct obj {
    int x, d, k;
};
obj seq[51];
// idx번째 원판, movedir : 0 시계 방향(오른), 1 반시계 방향(왼), k만큼 이동
void move(int idx, int movedir, int k) {
    int tmp[51] = {0,};
    if(movedir) {   // 반시계
        for(int i=0;i<M;i++) {
            int move_idx = i - k;
            if(move_idx < 0)
                move_idx = M - abs(i - k);
            tmp[move_idx] = map[idx][i];
        }
        for(int i=0;i<M;i++)
            map[idx][i] = tmp[i];
    }else{      // 시계
        for(int i=0;i<M;i++) {
            int move_idx = (i + k)%M;
            tmp[move_idx] = map[idx][i];
        }
        for(int i=0;i<M;i++)
            map[idx][i] = tmp[i];
    }    
}

// 인접 수 확인
void check_round(int x, int y, vector<pair<int, int> > &tmp) {
    int stand = map[x][y];
    bool find = false;
    if(y == 0) {
        if(stand == map[x][y+1]) {
            tmp.push_back(make_pair(x, y+1));
            find = true;
        }
        if(stand == map[x][M-1]) {
            tmp.push_back(make_pair(x, M-1));
            find = true; 
        }
    }
    else if(y == M-1) {
        if(stand == map[x][y-1]) {
            tmp.push_back(make_pair(x, y-1));
            find = true;
        }
        if(stand == map[x][0]) {
            tmp.push_back(make_pair(x, 0));
            find = true; 
        }
    }
    else {
        if(stand == map[x][y-1]) {
            tmp.push_back(make_pair(x, y-1));
            find = true;
        }
        if(stand == map[x][y+1]) {
            tmp.push_back(make_pair(x, y+1));
            find = true;           
        }
    }

    if(x == 0) {
        if(stand == map[x+1][y]) {
            tmp.push_back(make_pair(x+1, y));
            find = true;
        }
    }
    else if(x == N-1) {
        if(stand == map[x-1][y]) {
            tmp.push_back(make_pair(x-1, y));
            find = true; 
        }
    }
    else {
        if(stand == map[x+1][y]) {
            tmp.push_back(make_pair(x+1, y));
            find = true;
        }
        if(stand == map[x-1][y]) {
            tmp.push_back(make_pair(x-1, y));
            find = true;           
        }
    }
   
    if(find) 
        tmp.push_back(make_pair(x, y));
}
// 인접한 수들 삭제
bool remove_map() {
    vector<pair<int, int> > remove_list;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(map[i][j] == 0) continue;
            check_round(i, j, remove_list);
        }
    }
    if(remove_list.size() == 0)
        return false;
    else {
        for(auto it : remove_list) {
            map[it.first][it.second] = 0;
        }
    }
    return true;
}
// 합과 남아있는 원판 위의 수
pair<int, int> cnt_map() {
    pair<int, int> ret = make_pair(0, 0);
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(map[i][j] == 0) continue;
            ret.first += map[i][j];
            ret.second++;
        }
    }
    return ret;
}
// 전체 평균 보다 같거나 작은거 +1, 큰거 -1 처리
void check_map(float stand) {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(map[i][j] == 0) continue;
            else if(map[i][j] < stand) map[i][j]++;
            else if(map[i][j] > stand) map[i][j]--;
        }
    }
}
void simul() { 
    for(int i=0;i<T;i++) {
        // N번째 원판 전까지 x의 배수만 회전 
        for(int j=seq[i].x;j<=N;j+=seq[i].x) {
            move(j-1, seq[i].d, seq[i].k);
        }
        // 인접한 모든 값 삭제
        if(!remove_map()) {
            // 인접한 값이 하나도 없으면 전체 평균 보다 같거나 작은거 +1, 큰거 -1 처리
            pair<int, int> tmp = cnt_map();
            check_map((float)tmp.first / tmp.second);
        }
    }
}
void solve() {
    int answer = 0;
    simul();
    // 원판에 남은 수 합 구하기
    answer = cnt_map().first;
    cout<<answer<<"\n";
}
int main() 
{
    io;
    cin >> N >> M >> T;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> map[i][j];
        }
    }
    for(int i=0;i<T;i++) {
        cin >> seq[i].x >> seq[i].d >> seq[i].k;
    }
    solve();
    return 0;
}