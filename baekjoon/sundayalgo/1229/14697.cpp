/*
[BOJ] 14697. 방 배정하기
*/
#include <iostream>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, room[3];
int dp[301];

int main()
{
    io;
    for(int i=0;i<3;i++) cin>>room[i];
    cin>>n;
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            if(dp[i]) break;
            if(i >= room[j]) dp[i] = dp[i - room[j]];
        }
    }
    cout<<dp[n]<<"\n";
    return 0;
}