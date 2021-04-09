/*
[boj] 16935. 배열 돌리기 3
https://www.acmicpc.net/problem/16935
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int dir[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1}  }; // 시계 방향
const int ddir[4][2] = { {1,0}, {0,-1}, {0,1}, {-1,0}  }; // 시계 방향
int N, M, R;
int arr[101][101], buf_arr[101][101];
static inline void cmd_1() {
    for(int i=0;i<N;i++) 
        for(int j=0;j<M;j++) buf_arr[N-i-1][j] = arr[i][j];
}
static inline void cmd_2() {
    for(int i=0;i<N;i++) 
        for(int j=0;j<M;j++) buf_arr[i][M-j-1] = arr[i][j];
}
static inline void cmd_3() {
    for(int i=0;i<N;i++) 
        for(int j=0;j<M;j++) buf_arr[j][N-1-i] = arr[i][j];
    swap(N, M);
}
static inline void cmd_4() {
    for(int i=0;i<N;i++) 
        for(int j=0;j<M;j++) buf_arr[M-1-j][i] = arr[i][j];
    swap(N, M);
}
static inline void cmd_5() {
    int d = 0;
    for(int i=0;i<N;i+=N/2) {
        for(int j=0;j<M;j+=M/2) {
            int nx = dir[d][0] * N/2, ny = dir[d][1] * M/2;
            for(int x=0;x<N/2;x++) {
                for(int y=0;y<M/2;y++) {
                    buf_arr[nx + x + i][ny + y + j] = arr[i + x][j + y];
                }
            }
            d = (d + 1) % 4;
        }
    }
}
static inline void cmd_6() {
    int d = 0;
    for(int i=0;i<N;i+=N/2) {
        for(int j=0;j<M;j+=M/2) {
            int nx = ddir[d][0] * N/2, ny = ddir[d][1] * M/2;
            for(int x=0;x<N/2;x++) {
                for(int y=0;y<M/2;y++) {
                    buf_arr[nx + x + i][ny + y + j] = arr[i + x][j + y];
                }
            }
            d = (d + 1) % 4;
        }
    }
}
void excute_cmd(int cmd) {
    memset(buf_arr, 0, sizeof(arr));
    switch(cmd) {
        case 1: cmd_1(); break;
        case 2: cmd_2(); break;
        case 3: cmd_3(); break;
        case 4: cmd_4(); break;
        case 5: cmd_5(); break;
        case 6: cmd_6(); break;
    }
    memcpy(arr, buf_arr, sizeof(arr));
}
int main() 
{
    io;
    cin >> N >> M >> R;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
        }
    }
    while(R--) {
        int cmd; cin >> cmd;
        excute_cmd(cmd);
    }
    for(int i=0;i<max(N, M);i++) {
        bool chk = false;
        for(int j=0;j<max(N, M);j++) {
            if(arr[i][j] != 0) {
                chk = true;
                cout<<arr[i][j]<<" ";
            }
        }
        if(chk)
            cout<<"\n";
    }
    return 0;
}