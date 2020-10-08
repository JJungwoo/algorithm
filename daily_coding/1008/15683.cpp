/*
[boj] 15683. 감시 
https://www.acmicpc.net/problem/15683
*/

/*
CCTV는 회전시킬 수 있는데, 회전은 항상 90도 방향으로 해야 하며, 
감시하려고 하는 방향이 가로 또는 세로 방향이어야 한다.
CCTV는 감시할 수 있는 방향에 있는 칸 전체를 감시할 수 있다.
CCTV는 같은 CCTV끼리 감시 영역을 통과할수 있다.
문제 조건 제대로 읽고 상황 부여해서 상황마다 제대로 처리하기
*/
#include <iostream>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
struct camera {
    int x, y, k, d;
    camera(int _x, int _y, int _k, int _d) : x(_x), y(_y), k(_k), d(_d) {}
};
int field[9][9], tfield[9][9];
vector<camera> v, tmp;
bool visited[9][9][6];
int N, M, answer = 101;
void copy_map() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            tfield[i][j] = field[i][j];       
        }
    } 
}
void check_wall(int mx, int my, int d) {
    while(true) {
        if(mx < 0 || my < 0 || mx >= N || my >= M) break;
        if(tfield[mx][my] == 6) break;
        tfield[mx][my] = -1;
        mx += dir[d][0], my += dir[d][1];
    }
}
void check_map(int x, int y, int k, int d) {
    if(k == 5) {
        for(int i=0;i<4;i++) {
            int mx = x + dir[i][0], my = y + dir[i][1];
            check_wall(mx, my, i);
        }
    }else{
        if(k == 2) {
            for(int i=d;i<4;i+=2) {
                int mx = x + dir[i][0], my = y + dir[i][1];
                check_wall(mx, my, i);
            }
        }else if(k == 1) {
            int mx = x + dir[d][0], my = y + dir[d][1];
            check_wall(mx, my, d);
        }else if(k == 3) {
            for(int i=0;i<2;i++) {
                d = (d + i) % 4;
                int mx = x + dir[d][0], my = y + dir[d][1];
                check_wall(mx, my, d);
            }
        }else if(k == 4) {
            for(int i=0;i<3;i++) {
                d = (d + i) % 4;
                int mx = x + dir[d][0], my = y + dir[d][1];
                check_wall(mx, my, d);
            }
        }
    }
}
void solve(int idx) {
    if(idx == v.size()) {
        int score = 0;
        copy_map();
        for(int i=0;i<tmp.size();i++) {
            check_map(tmp[i].x, tmp[i].y, tmp[i].k, tmp[i].d);
        }

        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                if(tfield[i][j] == 0)
                    score++;

        if(score < answer)
            answer = score;
        return;
    }

    for(int i=idx;i<v.size();i++) {
        if(v[i].k == 1 || v[i].k == 3 || v[i].k == 4) {
            for(int j=0;j<4;j++) {
                if(visited[v[i].x][v[i].y][v[i].k]) continue;
                visited[v[i].x][v[i].y][v[i].k] = true;
                tmp.push_back(camera(v[i].x, v[i].y, v[i].k, j));
                solve(idx+1);
                tmp.pop_back();
                visited[v[i].x][v[i].y][v[i].k] = false;
            }
        }else if(v[i].k == 2) {
            for(int j=0;j<2;j++) {
                if(visited[v[i].x][v[i].y][v[i].k]) continue;
                visited[v[i].x][v[i].y][v[i].k] = true;
                tmp.push_back(camera(v[i].x, v[i].y, v[i].k, j));
                solve(idx+1);
                tmp.pop_back();
                visited[v[i].x][v[i].y][v[i].k] = false;
            }
        }else {
            if(visited[v[i].x][v[i].y][v[i].k]) continue; 
            visited[v[i].x][v[i].y][v[i].k] = true;
            tmp.push_back(camera(v[i].x, v[i].y, v[i].k, 0));
            solve(idx+1);
            tmp.pop_back();
            visited[v[i].x][v[i].y][v[i].k] = false;
        }
    }
}
int main() 
{
    io;
    cin >> N >> M;

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> field[i][j];
            if(field[i][j] != 0 && field[i][j] != 6)
                v.push_back(camera(i, j, field[i][j], 0));
        }
    }
    
    solve(0);
    cout<<answer<<"\n";
    return 0;
}