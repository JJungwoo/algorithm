/*
[BOJ] 11055. 가장 큰 증가 부분 수열
조건 이전 dp 값 보다 이전 dp 값과 현재 위치 값을 더한 값을 비교처리를 해줬어야 했었음..
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, ans;
int a[1001], dp[1001];

int main()
{
    io;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        dp[i] = a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(a[j] < a[i] && dp[i] < dp[j] + a[i]){
                dp[i] = a[i] + dp[j];
                //cout<<i<<","<<a[i]<<",j:"<<a[j]<<","<<dp[j]<<"\n";
            }
        }
        ans = max(ans, dp[i]);
    }
    cout<<ans<<"\n";
    return 0;
}