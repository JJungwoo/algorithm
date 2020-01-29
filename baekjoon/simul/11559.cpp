/*
[BOJ] 11559. Puyo Puyo
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define h 12
#define w 6

char map[h][w];
int ans;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool visited[h][w];
bool check;

void print_map(){
    for(int i=0;i<h;i++){       // same char clear
        for(int j=0;j<w;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void bfs(int x, int y, char value){
    int cnt = 1;
    queue<pair<int, int> > qp;
    vector<pair<int, int> > clear_list;
    memset(visited, 0, sizeof(visited));
    qp.push(make_pair(x,y));
    clear_list.push_back(make_pair(x,y));
    visited[x][y] = true;
    //cout<<"start: "<<x<<", "<<y<<", "<<value<<"\n";
    while(!qp.empty()){
        int tx = qp.front().first, ty = qp.front().second;
        visited[tx][ty] = true;
        //cout<<"qstart: "<<tx<<", "<<ty<<", "<<value<<"\n";
        qp.pop();
        for(int i=0;i<4;i++){
            int mx = tx + dir[i][0], my = ty + dir[i][1];
            if(mx < 0 || my < 0 || mx >= h || my >= w) continue;
            if(map[mx][my] != value) continue;
            if(visited[mx][my]) continue;
            //cout<<cnt<<" mx: "<<mx<<", my: "<<my<<", "<<value<<" = "<<map[mx][my]<<"\n";
            clear_list.push_back(make_pair(mx, my));
            cnt++;
            qp.push(make_pair(mx, my));
        }
    }
    if(cnt >= 4){
        for(auto k : clear_list){
            map[k.first][k.second] = '.';
        }
        check = true;
    }
}

void solve(int cnt){
    for(int i=0;i<h;i++){       // same char clear
        for(int j=0;j<w;j++){
            if(map[i][j] != '.'){
                bfs(i, j, map[i][j]);
            }
        }
    }
    // gravity
    for(int i=0;i<w;i++){       // 밑에서부터 떨구기
        for(int j=h-1;j>=0;j--){
            if(map[j][i] != '.'){
                int k = j;
                while(1){
                    if(k == h-1 || map[k+1][i] != '.'){
                        break;
                    }
                    else {
                        swap(map[k+1][i], map[k][i]);
                        k++;
                    }
                }
            }
        }
    }

    if(check){
        check = false;
        solve(cnt+1);
        ans = max(ans, cnt);
    }
}

int main()
{
    io;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>map[i][j];
        }
    }

    solve(1);
    cout<<ans<<"\n";

    return 0;
}
