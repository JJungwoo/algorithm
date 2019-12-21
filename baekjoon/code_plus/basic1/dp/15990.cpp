/*
[BOJ] 15990. 1,2,3 더하기 5
n=4를 1,2,3 의 합으로 나타내는 방법 
1+2+1, 1+3, 3+1 (연속 사용x)
점화식;; 
마지막으로 오는 수가 1이면? 그 앞에 올 수 있는 숫자는 2 또는 3이 된다.
마지막으로 오는 수가 2이면? 그 앞에 올 수 있는 숫자는 1 또는 3이 된다.
마지막으로 오는 수가 3이면? 그 앞에 올 수 있는 숫자는 1 또는 2이 된다.
D[n][i] 는 마지막에 오는 수가 i일 때, 1,2,3의 합으로 정수 n을 만드는 경우의 수가 된다.
D[n][1] = D[n-1][2] + D[n-1][3]
D[n][2] = D[n-2][1] + D[n-2][3]
D[n][3] = D[n-3][1] + D[n-3][2]
-> result = D[n][1] + D[n][2] + D[n][3]
*/
#include <cstdio>
using namespace std;
const int MAX = 1e9+9;
long long t, n, dp[100001][4];

int main()
{
    scanf("%lld", &t);
    dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
    while(t--){
        scanf("%lld", &n);
        for(int i=4;i<=n;i++){
            dp[i][1] = (dp[i-1][2] + dp[i-1][3])%MAX;
            dp[i][2] = (dp[i-2][1] + dp[i-2][3])%MAX;
            dp[i][3] = (dp[i-3][1] + dp[i-3][2])%MAX;
        }
        printf("%lld\n", (dp[n][1] + dp[n][2] + dp[n][3])%MAX); 
    }
    return 0;
}