/*
[BOJ] 1938. 통나무 옮기기
*/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, ans;
char map[51][51];

struct wood{
    int x,y;
    int dir;
};

wood my;
wood des;
int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool turn_check(int x, int y, int dir){   // dir 0 :가로, 1: 세로
    if(dir){
        if(x-1 < 0 || x+1 >= n || map[x-1][y] == 1 || map[x+1][y] == 1){
            return false;
        }
    }else {
        if(y-1 < 0 || y+1 >= n || map[x][y-1] == 1 || map[x][y+1] == 1){
            return false;
        }
    }
    return true;
}

bool move_check(int x, int y, int dir){   // dir 0 :가로, 1: 세로
    if(dir){
        if(y-1 < 0 || y+1 >= n || map[x][y-1] == 1 || map[x][y+1] == 1){
            return false;
        }
    }else{
        if(x-1 < 0 || x+1 >= n || map[x-1][y] == 1 || map[x+1][y] == 1){
            return false;
        }
    }
    return true;
}

void bfs(){
    queue<pair<pair<int, int>, pair<int, int> > > qp;
    qp.push(make_pair(make_pair(my.x, my.y), make_pair(my.dir, 0)));
    while(!qp.empty()){
        int x = qp.front().first.first, y = qp.front().first.second;
        int dir = qp.front().second.first, cnt = qp.front().second.second;
        cout<<"x:"<<x<<" y:"<<y<<" dir:"<<dir<<" cnt:"<<cnt<<"\n";
        if(des.x == x && des.y == y && des.dir == dir){
            ans = min(ans, cnt);
            return;
        }
        qp.pop();
        for(int i=0;i<5;i++){
            if(i == 4){ // turn
                if(!turn_check(x,y,dir)) continue;
                if(dir) qp.push(make_pair(make_pair(x,y),make_pair(0, cnt+1)));
                else qp.push(make_pair(make_pair(x,y),make_pair(1, cnt+1))); 
            }else {
                int mx = x + d[i][0], my = y + d[i][1];
                if(mx < 0 || my < 0 || mx >= n || my >= n) continue;
                if(!move_check(mx,my,dir)) continue;
                qp.push(make_pair(make_pair(mx,my),make_pair(dir, cnt+1)));
            }
        }
    }
}

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j] == 'B'){
                if(i+1 < n && i-1 >= 0 &&
                map[i+1][j] == 'B' && map[i-1][j] == 'B'){
                    my.x = i;
                    my.y = j;
                    my.dir = 1;
                }
                else if(j+1<n && j-1 >= 0 && 
                map[i][j+1] == 'B' && map[i][j-1] == 'B'){
                    my.x = i;
                    my.y = j;
                    my.dir = 0;
                }
            }
            else if(map[i][j] == 'E'){
                if(i+1 < n && i-1 >= 0 &&
                map[i+1][j] == 'E' && map[i-1][j] == 'E'){
                    des.x = i;
                    des.y = j;
                    des.dir = 1;
                }
                else if(j+1<n && j-1 >= 0 && 
                map[i][j+1] == 'E' && map[i][j-1] == 'E'){
                    des.x = i;
                    des.y = j;
                    des.dir = 0;
                }
            }
        }
    }
    
    bfs();    
    cout<<ans<<"\n";
    return 0;
}