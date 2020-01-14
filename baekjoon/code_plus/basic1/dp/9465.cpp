/*
[BOJ] 9465. 스티커6
쉽게 생각이 안났다.. 다시 풀어보자.
경우의 수는 2가지이다. 첫번째 현재 위치를 기준으로 현재 위에 카드를 선택하면 
이전 아래카드나 이전전 위에 최선의 경우를 선택할 수 있다.
두번째 현재 위치를 기준으로 현재 아래 카드를 선택하면 
이전 위에 카드나 이전전 아래 최선의 경우를 선택할 수 있다.
중요한건 현재 위치에 올 경우를 비교할 때 비교대상이 무엇인지 생각해보자.
현재 위치가 위라면 이전에 카드는 분명 아래일테고 이전 카드가 아래면 이전 카드의 전은 위 카드를 선택했다는
기저 상황이 발생한다. 그렇기 때문에 이전전은 무조건 비교하는 대상인 이전 카드가 아래인 경우를 배제한 이전전이
아래인 경우를 비교해줘야 한다. 
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int t, n;
int sticker[100001][2];
int dp[100001][2];

int main()
{
    io;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++)
                cin>>sticker[j][i];
        }
        dp[0][0] = sticker[0][0];
        dp[0][1] = sticker[0][1];
        dp[1][0] = sticker[1][0] + dp[0][1];
        dp[1][1] = sticker[1][1] + dp[0][0];
        for(int i=2;i<n;i++){
            dp[i][0] = sticker[i][0] + max(dp[i-1][1], dp[i-2][1]);
            dp[i][1] = sticker[i][1] + max(dp[i-1][0], dp[i-2][0]);
        }
        cout<<max(dp[n-1][0], dp[n-1][1])<<"\n";
    }

    return 0;
}