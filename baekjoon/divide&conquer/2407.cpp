/*
[boj] 2407. 조합
https://www.acmicpc.net/problem/2407
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
string dp[101][101];
string append_str(string a, string b) {
    int sum = 0;
    string ret = "";
    while (!a.empty() || !b.empty() || sum) {
        if (!a.empty()) {
            sum += a.back() - '0';
            a.pop_back();
        }
        if (!b.empty()) {
            sum += b.back() - '0';
            b.pop_back();
        }
        ret.push_back((sum % 10) + '0');
        sum /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
string combi(int n, int m) {
    if (n == m || m == 0)
        return "1";
    if (dp[n][m] != "")
        return dp[n][m];
    return dp[n][m] = append_str(combi(n - 1, m - 1), combi(n - 1, m));
}
int main() 
{
    io;
    int N, M;
    cin >> N >> M;
    cout << combi(N, M) << "\n";
    return 0;
}
