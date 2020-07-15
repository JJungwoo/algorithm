/*
[boj] 11051. 이항 계수2
https://www.acmicpc.net/problem/11051
*/

/*
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1

dp[i][j] = dp[i-1][j] + dp[i-1][j-1]
ref: https://glowdev.tistory.com/entry/2020-03-11-11051
*/
#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, k;
int dp[1001][1001] = {1,};
const int MOD = 10007;
int pascal(int n, int k){
    for(int i=1;i<=n;i++){
        dp[i][0] = dp[i][i] = 1;
        for(int j=1;j<=i;j++){
            dp[i][j] = (dp[i-1][j]%MOD + dp[i-1][j-1]%MOD)%MOD;
        }
    }
    return dp[n][k];
}
int main()
{
	io;
    cin>>n>>k;
    cout<<pascal(n, k)<<"\n";
	return 0;
}
