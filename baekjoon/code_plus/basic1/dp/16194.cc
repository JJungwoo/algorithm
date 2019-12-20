/*
[BOJ] 16194. 카드 구매하기2
memset 쓰면 틀림;; 왜지...
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, cardP[1001], dp[1001];

int main()
{
    scanf("%d", &n);
    fill(dp, dp+n+1, 1e9);
    for(int i=1;i<=n;i++) scanf("%d", &cardP[i]);
    dp[0] = 0;
    dp[1] = cardP[1];
    for(int i=2;i<=n;i++) {
        for(int j=1;j<=i;j++){
            dp[i] = min(dp[i], dp[i-j] + cardP[j]);
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}