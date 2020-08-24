/*
[boj] 1956. 운동 
https://www.acmicpc.net/problem/1956
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int INF = 1e9;
int city[401][401], dist[401][401];
int v,e;
int main() 
{
    io;
    cin>>v>>e;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            dist[i][j] = INF;
        }
    }
    for(int i=0;i<e;i++){
        int a, b, c;
        cin>>a>>b>>c;
        a--, b--;
        city[a][b] = c;
        dist[a][b] = c;
    }

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            for(int k=0;k<v;k++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int value = INF;
    for(int i=0;i<v;i++){
        value = min(value, dist[i][i]);
    }

    if(value == INF) cout<<"-1\n";
    else cout<<value<<"\n";    
    
    return 0;
}

