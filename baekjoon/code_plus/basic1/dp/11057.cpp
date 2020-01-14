/*
[BOJ] 11057. 오르막 수
*/
#include <iostream>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
int dp[1001][1001]; // 자릿수, 반복수

int main()
{
    io;
    cin>>n;
    for(int i=0;i<=10;i++){
        dp[0][i] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=10;j++){
            //cout<<i<<":"<<j<<"="<<dp[i][j]<<","<<dp[i][j-1]<<","<<dp[i-1][j-1]<<"\n"; 
            dp[i][j] = (dp[i][j-1] + dp[i-1][j])%10007;
        }
    }
    cout<<dp[n][10]%10007<<"\n";

    return 0;
}