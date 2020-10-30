/*
[boj] 2579. 계단 오르기
https://www.acmicpc.net/problem/2579

1) 계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 
즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
2) 연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
3) 마지막 도착 계단은 반드시 밟아야 한다.
*/

#include <iostream>
#include <cmath>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N;
int stairs[301], dp[301];
int main() 
{
    io;
    cin >> N;
    for(int i=1;i<=N;i++) {
        cin >> stairs[i];
    }

    dp[1] = stairs[1];
    for(int i=2;i<=N;i++) {
        dp[i] = max(stairs[i-1] + dp[i-3], dp[i-2]) + stairs[i];
    }
    cout<<dp[N]<<"\n";
    return 0;
}