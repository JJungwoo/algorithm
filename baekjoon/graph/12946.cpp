/*
[boj] 12946. 육각 보드
https://www.acmicpc.net/problem/12946
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int dir[6][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 0}, {1, -1}, {0, -1} };
int N, ans;
char board[51][51];
int board_coler[51][51];
void solve(int x, int y, int color) {
    ans = max(ans, color);
    board_coler[x][y] = color;
    for(int i=0;i<6;i++) {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if (board[nx][ny] != 'X') continue;
        if (board_coler[nx][ny] == -1) {
            solve(nx, ny, (color == 1 ? 2 : 1) );
        } else if (board_coler[nx][ny] == color) {
            cout << "3\n";
            exit(0);
        }   
    }
}
int main() 
{
    io;
    cin >> N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> board[i][j];
            board_coler[i][j] = -1;
        }
    }
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if (board[i][j] == 'X' && board_coler[i][j] == -1) {
                solve(i, j, 1);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}