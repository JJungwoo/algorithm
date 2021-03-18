/*
[programmers] 등굣길
https://programmers.co.kr/learn/courses/30/lessons/42898
*/
#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
#define MOD 1000000007
const int MAX_INT = 1e10;
set<pair<int, int>> s;
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=0;i<puddles.size();i++) {
        s.insert({puddles[i][0], puddles[i][1]});
    }
    dp[1][0] = 1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(s.find({i, j}) != s.end()) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            }
        }
    }
    return dp[n][m] % MOD;
}
