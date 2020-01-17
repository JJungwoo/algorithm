/*
[BOJ] 10844. 쉬운 계단 수
모든 경우의 수를 나열 한다.
n = 1 : 1 ~ 9
n = 2 : 12, 21, 23, 32, 34, 43, . . .
9, 17, 
이전 디피 수열 값 더하기 현재 인덱싱 값 
dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]
0 < j, j < 9
*/
#include <iostream>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int mod = 1e9;
long long n, ans;
long long dp[101][11];  // 자릿수, 끝나는 값.

int main()
{
    io;
    cin>>n;
    for(int i=1;i<10;i++) dp[1][i] = 1;

    for(int i=2;i<=n;i++){
        for(int j=0;j<=9;j++){
            if(j > 0) dp[i][j] += dp[i-1][j-1];
            if(j < 9) dp[i][j] += dp[i-1][j+1];
            dp[i][j] %= mod;
        }
    }
    for(int i=0;i<10;i++) ans += dp[n][i];
    cout<<ans%mod<<"\n";

    return 0;
}