/*
[BOJ] 2193. 이친수
n = 3
100, 101
answer = 2
ref: https://junco.tistory.com/62
*/
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main()
{
    io;
    int n; cin>>n;
    if(n==1 || n==2){
        cout<<1<<"\n";
        return 0;
    }
    vector< vector<ll> > dp(n+1, vector<ll>(1, 0));    // 10 + 100, 101, 010, 001, 000
    dp[1][1] = 1;  // 이친수 가장 맨앞 무조건 1로 시작해야 한다;;;
    dp[1][0] = 0;
    for(int i=2;i<=n;i++){
        dp[i][0] = dp[i-1][1] + dp[i-1][0]; // 0으로 끝나면 0, 1 둘다 올수 있다.
        dp[i][1] = dp[i-1][0];              // 1로 끝나면 0만 올수 있다.
    }
    cout<<dp[n][0] + dp[n][1]<<"\n";

    return 0;    
}
