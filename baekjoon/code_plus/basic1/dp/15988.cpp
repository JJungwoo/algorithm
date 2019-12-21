/*
[BOJ] 15988. 1, 2, 3 더하기 3
*/
#include <cstdio>
using namespace std;
const long mod = 1e9 + 9;
long long dp[1000001];
int n, t;
int main()
{
    scanf("%d", &t);
    dp[1] = 1;      // 1
    dp[2] = 2;      // 1+1, 2;
    dp[3] = 4;      // 1+1+1, 1+2, 2+1, 3;
    // 4 = 7 (1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2, 1+3, 3+1);
    while(t--){
        scanf("%d", &n);
        for(int i=4;i<=n;i++){
            dp[i] = (dp[i-1] + dp[i-2] + dp[i-3])%mod;
        }
        printf("%lld\n", dp[n]%mod);
    }
    return 0;
}