/*
[BOJ] 13460. 구슬 탈출 2
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, m;
int map[10][10];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

struct obj_info{
    int x, y;
    char t;
};

obj_info oRed;
obj_info oBlue;
obj_info oGoal;

bool check_move(int x, int y){
    if(map[x][y] != '.') return false;
    return true;
}

void move_obj(int rx, int ry, int bx, int by, int i){
    switch(dir){
        case 0:
        if(rx > bx){
            while(1){
                int move = rx + dir[i][0];
                if(check_move(move, ry) == false) break;
                swap(map[rx][ry], map[move][ry]);
            }
            while(1){
                int move = rx + dir[i][0];
                if(check_move(move, ry) == false) break;
                swap(map[rx][ry], map[move][ry]);
            }
        }
        break;
        case 1:
        if(rx > bx){
            while(1){
                int move = rx + dir[i][0];
                if(check_move(move, ry) == false) break;
                swap(map[rx][ry], map[move][ry]);
            }
            while(1){
                int move = rx + dir[i][0];
                if(check_move(move, ry) == false) break;
                swap(map[rx][ry], map[move][ry]);
            }
        }                    
        break;
        case 2:
        if(rx > bx){
            while(1){
                int move = rx + dir[i][0];
                if(check_move(move, ry) == false) break;
                swap(map[rx][ry], map[move][ry]);
            }
            while(1){
                int move = rx + dir[i][0];
                if(check_move(move, ry) == false) break;
                swap(map[rx][ry], map[move][ry]);
            }
        }
        break;
        case 3:
        if(rx > bx){
            while(1){
                int move = rx + dir[i][0];
                if(check_move(move, ry) == false) break;
                swap(map[rx][ry], map[move][ry]);
            }
            while(1){
                int move = rx + dir[i][0];
                if(check_move(move, ry) == false) break;
                swap(map[rx][ry], map[move][ry]);
            }
        }
        break;
    }

}

void bfs()
{
    queue<pair<pair<int, int>, pair<int, int> > > qp;
    rqp.push(make_pair(make_pair(oRed.x, oRed.y), make_pair(oBlue.x, oBlue.y)));
    while(!rqp.empty()){
        int rx = qp.front().first.first, ry = qp.front().first.second;
        int bx = qp.front().second.first, by = qp.front().second.second;
        qp.pop();
        for(int i=0;i<4;i++){   // up, down, left, right
            int mrx = rx + dir[i][0], mry = ry + dir[i][1];
            int mbx = bx + dir[i][0], mby = by + dir[i][1];
            int rover = 0, bover = 0;
            while(rover + bover < 2){
                mrx = mrx + dir[i][0], mry = mry + dir[i][1];
                mbx = mbx + dir[i][0], mby = mby + dir[i][1];
                if(rover == 0 && check_move() == false){
                    swap(map[mrx][mry],map[mrx][mry])
                    rover++;
                }
                if(bover == 0 && check_move() == false){
                    bover++;
                }
    
            }
            
        }
    }
}

int main()
{
    io;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
            if(map[i][j] == 'O'){
                oGoal.x = i;
                oGoal.y = j;
                oGoal.t = 'O';
            }else if(map[i][j] == 'R'){
                oRed.x = i;
                oRed.y = j;
                oRed.t = 'R';
            }else if(map[i][j] == 'B'){
                oBlue.x = i;
                oBlue.y = j;
                oBlue.t = 'B';
            }
        }
    }
    bfs();

    return 0;
}