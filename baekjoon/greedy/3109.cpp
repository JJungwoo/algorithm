/*
[boj] 3109. 빵집
https://www.acmicpc.net/problem/3109

단순하게 위, 옆, 아래순으로 검색하면 아래와 같은 상황에서 1이 아닌 0으로 오답이 발생한다.
5 5
.x.x.
.x.x.
..xx.
.x...
.x.x.
0
그렇기때문에 dp 배열을 사용해야한다.
중간까지의 과정에 올수있는 경우의 수를 모두 계산해야한다.
왜지 dfs도 가능하지만 dp로 가는 방법도 있을텐데.. 아무도 안하네
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int r,c,ans;
char map[10001][501];
int dfs(int x, int y){
    if(x < 0 || x >= r) return 0;
    if(map[x][y] == 'x') return 0;
    map[x][y] = 'x';
    if(y == c-1) return 1;

    if(dfs(x-1, y+1)) return 1;
    if(dfs(x, y+1)) return 1;
    if(dfs(x+1, y+1)) return 1;

    return 0;
}
int main()
{
    io;
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>map[i][j];
        }
    }
    for(int i=0;i<r;i++){
        ans += dfs(i, 0);
    }
    cout<<ans<<"\n";
    return 0;
}
/*
int r,c,ans;
char map[10001][501];
int dp[10001][501];
int main()
{
    io;
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>map[i][j];
        }
    }

    for(int i=0;i<r;i++){
        dp[i][0] = 1;
        for(int j=1;j<c;j++){
            if(map[i][j] == 'x') continue;
            //dp[i][j] = max(dp[i-1][j-1], max(dp[i][j-1], dp[i+1][j-1]));
            if(i-1 >= 0 && dp[i-1][j-1]){
                dp[i][j] = 1;
            }else if(dp[i][j-1]){
                dp[i][j] = 1;
            }else if(i+1 < r && map[i+1][j-1] != 'x'){
                dp[i][j] = 1;
            }
        }
    }
    for(int i=0;i<r;i++){
        if(map[i][c-1] == 'x' || map[i][c-2] == 'x') continue;
        ans += dp[i][c-2];
    }
    cout<<ans<<"\n";
    return 0;
}
*/