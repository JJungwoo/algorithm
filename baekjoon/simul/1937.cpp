/*
[boj] 1937. 욕심쟁이 판다 
https://www.acmicpc.net/problem/1937
*/

#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int dir[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int field[501][501], dp[501][501];
int answer;
int solve(int x, int y, int N) {
    if(dp[x][y])
        return dp[x][y];
    dp[x][y] = 1;
    for(int i=0;i<4;i++) {
        int mx = x + dir[i][0], my = y + dir[i][1];
        if(mx < 0 || my < 0 || mx >= N || my >= N) continue;
        if(field[mx][my] <= field[x][y]) continue;
        dp[x][y] = max(dp[x][y], solve(mx, my, N) + 1);
    }
    return dp[x][y];
}
int main() 
{
    io;
    int N;
    cin >> N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> field[i][j];
        }
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            answer = max(answer, solve(i, j, N));
        }
    }


    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    cout<<answer<<"\n";
    return 0;
}