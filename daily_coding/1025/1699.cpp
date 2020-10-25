/*
[boj] 1699. 제곱수의 합
https://www.acmicpc.net/problem/1699
*/

#include <iostream>
#include <cmath>
#include <cstring>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, dp[100001];
int main() 
{
    io;
    cin >> N;
    for(int i=0;i<=N;i++) {
        dp[i] = 999999;
    }
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    if(N <= 3) {
        cout<<dp[N]<<"\n";
        return 0;
    }
    for(int i=4;i<=N;i++) {
        int tmp = sqrt(i);
        for(;tmp>0;tmp--) {
            if(i - (tmp*tmp) == 0)
                dp[i] = min(dp[i - (tmp * tmp)], dp[i]);
            else
                dp[i] = min(dp[i - (tmp * tmp)] + 1, dp[i]);
        }
    }
    cout<<dp[N]<<"\n";
    return 0;
}