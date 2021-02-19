/*
[boj] 9084. 동전
https://www.acmicpc.net/problem/9084
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    io;
    int T, N, M;
    cin >> T;
    while(T--) {
        cin >> N;
        vector<int> gold(N);
        for(int i=0;i<N;i++) {
            cin >> gold[i];
        }
        cin >> M;
        vector<int> dp(M+1);
        dp[0] = 1;
        for(int i=0;i<N;i++) {
            for(int j=1;j<=M;j++) {
                if(j - gold[i] >= 0) {
                    dp[j] = dp[j] + dp[j - gold[i]];
                }
            }
        }
        cout<<dp[M]<<"\n";
    }
    return 0;
}