/*
[boj] 11404. 플로이드
*/

#include <iostream>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int INF = 10000001;
int n, m;
int map[101][101];
int main()
{
    io;
    cin>>n>>m;
    fill(&map[0][0], &map[100][100], INF);
    for(int i=0;i<m;i++){
        int a, b, c;
        cin>>a>>b>>c;
        a--, b--;
        map[a][b] = min(map[a][b], c);
    }

    for(int i=0;i<n;i++) map[i][i] = 0;

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j] == INF) cout<<"0 ";
            else cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}