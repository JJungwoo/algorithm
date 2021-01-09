/*
[boj] 1956. 운동
https://www.acmicpc.net/problem/1956
*/

#include <iostream>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int INF = 1e9;
int V, E, dist[401][401];
int main()
{
    io;
    cin >> V >> E;
    for(int i=0;i<=V;i++)
        for(int j=0;j<=V;j++)
            dist[i][j] = INF;
    while(E--) {
        int A, B, C;
        cin >> A >> B >> C;
        dist[A][B] = min(dist[A][B], C);
    }

    for(int i=1;i<=V;i++) {
        for(int j=1;j<=V;j++) {
            for(int k=1;k<=V;k++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = INF;
    for(int i=1;i<=V;i++) {
        ans = min(ans, dist[i][i]);
    }

    if(ans == INF) cout<<"-1\n";
    else cout<<ans<<"\n";

    return 0;
}