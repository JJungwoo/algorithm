/*
[boj] 5557. 1학년
https://www.acmicpc.net/problem/5557
*/

#include <iostream>
#include <cstring>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long long dp[101][21];
long long dfs(int idx, int size, int sum, vector<int> &tmp){
    if(sum < 0 || sum > 20) return 0;
    if(idx == size-1) {
        if(sum == tmp[size-1])
            return 1;
        return 0;
    }
    if(dp[idx][sum] != -1)
        return dp[idx][sum];
    return dp[idx][sum] = dfs(idx+1, size, sum - tmp[idx], tmp) + dfs(idx+1, size, sum + tmp[idx], tmp);
}
int main() 
{
    io;
    int N;
    long long ans = 0;
    cin >> N;
    vector<int> numbers(N, 0);
    for(int i=0; i<N; i++)
        cin >> numbers[i];

    memset(dp, -1, sizeof(dp));
    dp[0][numbers[0]] = 1; 
    ans = dfs(1, N, numbers[0], numbers);
    cout << ans << "\n";
    return 0;
}

