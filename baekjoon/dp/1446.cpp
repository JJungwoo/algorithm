/*
[boj] 1446. 지름길
https://www.acmicpc.net/problem/1446
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define START 0
#define END 1
#define SHORTPATH 2
int main() 
{
    io;
    int N, D;
    cin >> N >> D;
    vector<int> dp(D+1, 0);
    vector<vector<int>> vv;
    for(int i=0;i<N;i++) {
        int start, end, shortpath;
        cin >> start >> end >> shortpath;
        vv.push_back({start, end, shortpath});
    }
    
    for(int i=1;i<=D;i++) {
        dp[i] = dp[i-1] + 1;
        for(auto it : vv) {
            if (i == it[END]) {
                dp[i] = min(dp[i], it[SHORTPATH] + dp[i - it[END] + it[START]]);
            }
        }
    }
    cout<<dp[D]<<"\n";
    return 0;
}
