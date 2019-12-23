/*
[BOJ] 2156. 포도주 시식
모두 마시고 다 마신 자리에 놓는다.
연속으로 3잔 마실 수 없다.
ex) 6, 10, 13, 9, 8, 1
1, 2, 4, 5 ==> 33 최대
for에서 i를 현재 위치로 두고 현재 위치에 올수 있는 경우의 수는 다음과 같다.
i = i-1 + i-2
i = i-1 + i-3
i = i-2 + i-3
어떻게 이걸 풀어서 dp에 기록할까?..
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
vector<int> wine;
vector<int> dp;
int main()
{
    io;
    cin>>n;
    wine.resize(n+1, 0);
    dp.resize(n+1, 0);
    for(int i=1;i<=n;i++) cin>>wine[i];
    if(n==1 || n==2){
        cout<<wine[1]+wine[2]<<"\n";
        return 0;
    }
    dp[1] = wine[1];
    dp[2] = wine[2];
    for(int i=3;i<=n;i++) {
        dp[i] = max(max(dp[i-1]+wine[i], dp[i-2]+wine[i]), dp[i-1]+dp[i-2]);
        cout<<i<<":"<<dp[i]<<"\n";
    }
    cout<<dp[n]<<"\n";

    return 0;
}