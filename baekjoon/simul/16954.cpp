/*
[BOJ] 16954. 움직이는 미로 탈출
1초마다 모든 벽이 아래에 있는 행으로 한 칸씩 내려가고 가장 아래에 있어서 아래에 행이 없다면 벽이 사라지게 된다.
1초에 인접한 한 칸 또는 대각선 방향으로 인접한 한 칸으로 이동하거나, 현재 위치에 서 있을 수 있다.
빈칸만 이동 가능, 욱제가 1초동안 먼저 이동하고 벽이 이동한다.
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int ans;
char map[8][8];
int dir[9][2] = {
    {-1,-1},{-1,0},{-1,1},
    {0,-1},{0,0},{0,1},
    {1,-1},{1,0},{1,1}
    };

void print_map()
{
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void move_wall()
{
    for(int i=7;i>=0;i--){
        for(int j=7;j>=0;j--){
            if(i == 7){
                map[i][j] = '.';
            }
            else if(map[i][j] == '#'){
                swap(map[i][j], map[i+1][j]);
            }
        }
    }
}

void solve()
{
    queue<pair<int, int> > qp;
    qp.push(make_pair(7,0));
    while(!qp.empty()){
        int x = qp.front().first, y = qp.front().second;
        qp.pop();
        vector<pair<int, int> > vp;
        if(x == 0 && y == 7){
            ans = 1;
            return;
        }
        for(int i=0;i<9;i++){
            int mx = x + dir[i][0], my = y + dir[i][1];
            if(mx < 0 || my < 0 || mx >= 8 || my >= 8) continue;
            if(map[mx][my] == '#') continue;
            vp.push_back(make_pair(mx,my));
            //cout<<"mx:"<<mx<<",my:"<<my<<"\n";
        }
        //cout<<vp.size()<<"\n";
        move_wall();
        //print_map();
        for(int i=0;i<vp.size();i++){
            int mx = vp[i].first, my = vp[i].second;
            //cout<<"mx:"<<mx<<",my:"<<my<<"\n";
            if(map[mx][my] == '#') continue;
            qp.push(make_pair(mx,my));
        }
    }

}

int main()
{
    io;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>map[i][j];
        }
    }
    solve();
    cout<<ans<<"\n";
    return 0;
}