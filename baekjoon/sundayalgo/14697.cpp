/*
[BOJ] 14697. 방 배정하기
*/
#include <iostream>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define max(a,b) (a>b?a:b)
int a,b,c,n;
int dp[301];

int main()
{
    io;
    cin>>a>>b>>c>>n;
   
    dp[0] = dp[a] = dp[b] = dp[c] = 1;
    int s = max(a,max(b,c));
    for(int i=s+1;i<=n;i++){
        dp[i] += dp[i-a] + dp[i-b] + dp[i-c];
        /*for(int i=0;i<=n;i++){
            cout<<dp[i]<<" ";
        }
        cout<<"\n";*/
    }

    if(dp[n]) cout<<"1\n";
    else cout<<"0\n";
    return 0;
}