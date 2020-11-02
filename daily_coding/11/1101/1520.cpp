/*
[boj] 1520. 내리막 길 
https://www.acmicpc.net/problem/1520
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
int M, N, map[501][501];
long long dp[501][501];
int cnt = 0;
int dfs(int x, int y) {
    if(dp[x][y] != -1)
        return dp[x][y];
    if(x == 0 && y == 0)
        return 1;
    dp[x][y] = 0;
    for(int i=0;i<4;i++) {
        int mx = x + dir[i][0], my = y + dir[i][1];
        if(mx < 0 || my < 0 || mx >= M || my >= N) continue;
        if(map[x][y] < map[mx][my]) {
            dp[x][y] += dfs(mx, my);
        }        
    }
    return dp[x][y];
}
int main() 
{
    io;
    cin >> M >> N;
    for(int i=0;i<M;i++) {
        for(int j=0;j<N;j++) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
    cout<<dfs(M-1, N-1)<<"\n";
    return 0;
}
