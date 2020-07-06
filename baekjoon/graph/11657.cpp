/*
[boj] 11657. 타임머신
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int INF = 987654321;
int n, m;
vector<pair<int, int> > city[500];
int dist[500];
int main()
{
    io;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        dist[i] = INF;

    for(int i=0;i<m;i++){
        int a, b, c;
        cin>>a>>b>>c;
        a--, b--;
        city[a].push_back(make_pair(b,c));
    }

    dist[0] = 0;
    bool cycle = false;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(auto &it : city[j]){
                int next = it.first, d = it.second;
                if(dist[j] != INF && dist[next] > dist[j] + d){
                    dist[next] = dist[j] + d;
                    if(i == n-1) cycle = true;
                }
            }
        }
    }
    if(cycle) cout<<"-1\n";
    else{
        for(int i=1;i<n;i++)
            if(dist[i] != INF) cout<<dist[i]<<"\n";
            else cout<<"-1\n";
    }
    
    return 0;
}