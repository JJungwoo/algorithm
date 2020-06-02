/*
[boj] 1922. 네트워크 연결
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, m, ans;
vector<int> com[1001];
int dist[1001][1001];
priority_queue<pair<int, int> > pq;     // value, next;
bool visited[1001];
int main()
{
    io;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin>>a>>b>>c;
        a--,b--;
        com[a].push_back(b);
        com[b].push_back(a);
        dist[a][b] = c;
        dist[b][a] = c;
    }

    for(auto it : com[0]){
        pq.push(make_pair(-dist[0][it], it));
        //cout<<"1 -> " <<it+1<<"\n";
    }        
    visited[0] = true;

    while(!pq.empty()){
        int here = pq.top().second;
        int value = -pq.top().first;
        //cout<<"here: "<<here+1<<" value: "<<value<<" qsize "<<pq.size()<<"\n";
        pq.pop();
        if(visited[here]) continue;
        visited[here] = true;
        ans += value;
        
        for(auto it : com[here]){
            int next = it;
            //cout<<here+1<<" -> "<<next+1<<"\n";
            if(visited[next] == false){
                cout<<dist[here][next]<<"\n";
                pq.push(make_pair(-dist[here][next], next));
            }
        }
    }

    cout<<ans<<"\n";
    return 0;
}