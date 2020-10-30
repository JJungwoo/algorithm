/*
[boj] 11048. 이동하기
https://www.acmicpc.net/problem/11048
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, M;
int map[1001][1001], dp[1001][1001];
int main() 
{
    io;
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> map[i][j];
        }
    }
    dp[0][0] = map[0][0];
    dp[1][0] = map[1][0];
    dp[0][1] = map[0][1];

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(i-1 >= 0)
                dp[i][j] = max(dp[i-1][j] + map[i][j], dp[i][j]);
            if(j-1 >= 0)
                dp[i][j] = max(dp[i][j-1] + map[i][j], dp[i][j]);
            if(i - 1 >= 0 && j - 1 >= 0)
                dp[i][j] = max(dp[i-1][j-1] + map[i][j], dp[i][j]);
        }
    }
    cout<<dp[N-1][M-1]<<"\n";
    return 0;
}