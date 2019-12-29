/*
[BOJ] 1309. 동물원
2차원 배열 가로 2칸 세로 N칸으로 된 동물원에 사자가 있는데, 사자는 위아래, 양옆으로 같이 있을 수 없다.
이때 사자를 배치할 수 있는 경우의 수를 출력하는 것.
n번째 위치에 현재 가능한 경우의 수가 올 수 있다면
dp[n][0] : 사자가 아예 없는 경우
dp[n][1] : 사자가 오른쪽에 있는 경우
dp[n][2] : 사자가 왼쪽에 있는 경우
*/
#include <iostream>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
int dp[100001][3];

int main()
{
    io;
    cin>>n;
    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    for(int i=2;i<=n;i++){
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2])%9901;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2])%9901;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1])%9901;
    }
    cout<<(dp[n][0] + dp[n][1] + dp[n][2])%9901<<"\n";
    return 0;
}