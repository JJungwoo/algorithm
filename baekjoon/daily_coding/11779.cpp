/*
[boj] 11779. 최소비용 구하기 2
https://www.acmicpc.net/problem/11779
*/

#include <iostream>
#include <queue>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int INF = 1e9;
int n,m,a,b;
struct obj{
    int t, c;
    bool operator < (obj a) const { return c > a.c; }
    vector<int> load;
};
int dist[1000];
vector<obj> bus[1000];
vector<int> solve(){
    priority_queue<obj> pq; // 현재 위치, 현재 비용
    pq.push({a, 0});
    dist[a] = 0;
    while(!pq.empty()){
        int cur = pq.top().t, cost = pq.top().c;
        vector<int> tmp = pq.top().load;
        tmp.push_back(cur+1);
        pq.pop();
        if(cur == b) 
            return tmp;
        if(dist[cur] < cost) 
            continue;
        for(auto next : bus[cur]){
            if(dist[next.t] > next.c + cost) {
                dist[next.t] = next.c + cost;
                pq.push({next.t, dist[next.t], tmp});
            }
        }
    }
}
int main() 
{
    io;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int s, d, c;
        cin>>s>>d>>c;
        bus[s-1].push_back({d-1, c});
    }
    cin>>a>>b;
    a--, b--;
    for(int i=0;i<n;i++) 
        dist[i] = INF;
    vector<int> ans = solve();
    cout<<dist[b]<<"\n";
    cout<<ans.size()<<"\n";
    for(auto it : ans)
        cout<<it<<" ";
    cout<<"\n";
    return 0;
}

