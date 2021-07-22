/*
[boj] 15989. 1, 2, 3 더하기 4
https://www.acmicpc.net/problem/15989
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main() 
{
    io;
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> dp(n+1);
        dp[0] = 1;
        for(int i=1;i<=3;i++) {
            for(int j=1;j<=n;j++) {
                if (j - i < 0) continue;
                dp[j] += dp[j-i];
            }
        }
        cout<<dp[n]<<"\n";
    }
    
    return 0;
}
