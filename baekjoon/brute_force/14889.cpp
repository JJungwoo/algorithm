/*
[boj] 14889. 스타트와 링크
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int INF = 1e9;
int n, ans = INF;
int map[20][20];
bool visited[20];
void solve(int cur, int cnt){
    if(cnt >= n) return;
    if(cnt == n/2){
        int asum = 0, bsum = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i] && visited[j]){
                    asum += map[i][j];
                }else if(!visited[i] && !visited[j]){
                    bsum += map[i][j];
                }
            }
        }
        int diff = abs(asum - bsum);
        if(ans > diff){
            ans = diff;
        }
        return;
    }

    for(int i=cur;i<n;i++){
        if(visited[i]) continue;
        visited[i] = true;
        solve(i+1, cnt+1);
        visited[i] = false;
    }
}
int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    solve(0,0);
    cout<<ans<<"\n";
    return 0;
}