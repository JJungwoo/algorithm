/*
[BOJ] 14002. 가장 긴 증가하는 부분 수열 4
ref: https://velog.io/@pa324/boj-14002-%EA%B0%80%EC%9E%A5-%EA%B8%B4-%EC%A6%9D%EA%B0%80%ED%95%98%EB%8A%94-%EB%B6%80%EB%B6%84-%EC%88%98%EC%97%B4-4-r8k2j0z7qy
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, ans=1, hi;
int a[1001];
int dp[1001];
int seq[1001];

void go(int p){
    if(p == 0) return ;
    go(seq[p]);
    cout<<a[p]<<" ";
}
int main()
{
    io;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        dp[i] = 1;
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[i] > a[j] && dp[i] < dp[j]+1){
                dp[i] = dp[j] + 1;
                //dp[i] = max(dp[j] + 1, dp[i]);
                seq[i] = j;
                //cout<<a[i]<<","<<a[j]<<","<<dp[i]<<","<<dp[j]<<"\n";
            }
        }
        //ans = max(ans, dp[i]);
        if(ans < dp[i]){
            ans = dp[i];
            hi = i;
        }
    }

    cout<<ans<<"\n";
    go(hi);
    
    return 0;
}