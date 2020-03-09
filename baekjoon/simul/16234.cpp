/*
[BOJ] 16234. 인구 이동
국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루동안 연다.
(연합의 인구수)/(연합을 이루고 있는 칸의 개수)
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, l, r, ans, cnt, team_value; // L up, R down 
int map[51][51];
int team[51][51];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

inline bool check_move(int x1, int y1, int x2, int y2){
    int diff = abs(map[x1][y1] - map[x2][y2]);
    if(diff >= l && diff <= r) return true;
    else return false;
}

void dfs(int x, int y){
    if(team[x][y]) return;
    team[x][y] = true;

    for(int i=0;i<4;i++){
        int mx = x + dir[i][0], my = y + dir[i][1];
        if(mx < 0 || my < 0 || mx >= n || my >= n) continue;
        if(team[mx][my]) continue;
        if(!check_move(x,y,mx,my)) continue;
        cnt++;
        team[mx][my] = true;
        team_value += map[mx][my];
    }
}

void divide(int val){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(team[i][j]){
                map[i][j] = val;
                team[i][j] = false;
            }
        }
    }
}

bool check_map(){
    bool check = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!team[i][j]){
                cnt = 1;
                dfs(i,j);
                if(cnt > 1){
                    team_value /= cnt;
                    divide(team_value);
                    check = true;
                }
            }
        }
    }
    if(check) return true;
    return false;
}

void solve(){
    while(true){
        bool moved = false;
        memset(team, 0, sizeof(team));
        team_value = 0;
        if(check_map()){
            ans++;
        }else {
            break;
        }
    }
}

int main()
{
    io;
    cin>>n>>l>>r;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    solve();
    cout<<ans<<"\n";
    return 0;
}