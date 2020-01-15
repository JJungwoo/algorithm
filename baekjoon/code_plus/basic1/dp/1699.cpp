/*
[BOJ] 1699. 제곱수의 합
ref: https://velog.io/@pa324/2019-11-04-1011-%EC%9E%91%EC%84%B1%EB%90%A8-c2k2jpzjj9
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int cnt = 0, n; 
int dp[100001];

int main()
{
    io;
    cin>>n;
    for(int i=0;i<=n;i++) dp[i] = i;
    for(int i=2;i<=n;i++){
        for(int j=2;j*j<=i;j++){
            dp[i] = min(dp[i], dp[i-j*j] + 1);

        }
    }

    cout<<dp[n]<<"\n";
    return 0;
}