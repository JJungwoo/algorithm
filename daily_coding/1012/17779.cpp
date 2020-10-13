/*
[boj] 17779. 게리멘더링 2
https://www.acmicpc.net/problem/17779
*/

#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define MAX 101 * 101 * 21
int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
int N;
int map[21][21];
void print_map(int tmp[21][21]) {
    cout<<"print_map()\n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout<<tmp[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void init_round(int x, int y, int d1, int d2, int tmp[21][21]) {
    for(int i=0;i<=d1;i++)
        tmp[x+i][y-i] = 0;
    for(int i=0;i<=d2;i++)
        tmp[x+d1+i][y-d1+i] = 0;
    for(int i=0;i<=d1;i++)
        tmp[x+d1+d2-i][y-d1+d2-i] = 0;
    for(int i=0;i<=d2;i++) 
        tmp[x+d2-i][y+d2-i] = 0;
}
void fill_space(int x, int y, int tmp[21][21]) {
    queue<pair<int, int> > q;
    q.push(make_pair(x+1, y));
    tmp[x+1][y] = 0;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(int i=0;i<4;i++) {
            int mx = cur.first + dir[i][0], my = cur.second + dir[i][1];
            if(mx < 0 || my < 0 || mx >= N || my >= N) continue;
            if(tmp[mx][my] == 0) continue;
            tmp[mx][my] = 0;
            q.push(make_pair(mx, my));
        }
    }
}
int divide_and_counting(int x, int y, int d1, int d2) {
    int ret = MAX, section[5] = {0, };
    int tmp_map[21][21];
    memset(tmp_map, -1, sizeof(tmp_map));

    init_round(x, y, d1, d2, tmp_map);
    fill_space(x, y, tmp_map);

    print_map(tmp_map);
    for(int r=0;r<N;r++) {
        for(int c=0;c<N;c++) {
            if(tmp_map[r][c] == 0) continue;
            else if(0 <= r && r < x+d1 && 0 <= c && c <= y) {
                tmp_map[r][c] = 1;
            }else if(0 <= r && r <= x + d2 && y < c && c <= N) {
                tmp_map[r][c] = 2;
            }else if(x + d1 <= r && r <= N && 0 <= c && c < y - d1 + d2) {
                tmp_map[r][c] = 3;
            }else if(x + d2 < r && r <= N && y - d1 + d2 <= c && c <= N) {
                tmp_map[r][c] = 4;
            }
        }
    }
    cout<<"구역 나눈 다음\n";
    print_map(tmp_map);

    // 전체 구역 계산
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            section[tmp_map[i][j]] += map[i][j];
        }
    }

    sort(section, section + 5);
    ret = abs(section[0] - section[4]);

    cout<<"x: "<<x<<" y: "<<y<<" d1: "<<d1<<" d2: "<<d2<<"\n";
    print_map(tmp_map);
    cout<<section[0]<<" - "<<section[4]<<" = "<<ret<<"\n";
    return ret;
}

int simul(int x, int y) {
    int ret = MAX;
    // d1 1 -> d2 1 2 3 ... 
    int d1 = 1, d2 = 1;
    for(;x+d1+d2<N;d1++) {
        for(;x+d1+d2<N;d2++) {
            if(y-d1 < 0 || y+d2 >= N) continue;
            int tmp = divide_and_counting(x, y, d1, d2);
            ret = min(ret, tmp);
        }
        d2 = 1;
    }
    return ret;
}
void solve() {
    int answer = MAX;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            answer = min(answer, simul(i, j));
        }
    } 
    cout<<answer<<"\n";
}
int main() 
{
    io;
    cin >> N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> map[i][j];
        }
    }
    solve();
    return 0;
}