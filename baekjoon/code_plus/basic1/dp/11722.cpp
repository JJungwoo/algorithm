/*
[BOJ] 11722. 가장 긴 감소하는 부분 수열
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
        dp[i] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(a[i] < a[j] && dp[i] <= dp[j]){
                dp[i] = dp[j]+1;
            }
        }
        ans = max(ans, dp[i]);
    }
    
    cout<<ans<<"\n";

    return 0;
}