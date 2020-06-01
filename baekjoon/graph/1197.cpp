/*
[boj] 1197. 최소 스패닝 트리
사용한 메모리 : 8096km -> 8mb
시간 : 64ms
전체 총 정점 수 : 10,000 
처음 메모리 초과가 발생하였는데, 가중치 값을 2차원 배열로 설정하여
10,000 * 10,000 * 4(int) = 400mb가 되어 128mb 메모리 제한에 걸리게 된다.
따라서 가중치 배열을 지우고 graph 벡터에 pair로 가중치값을 더해줬다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int v, e, ans;
vector<pair<int, int>> graph[10001];
priority_queue<pair<int, int>> pq;
bool visited[10001];
int main()
{
    io;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int a, b, c;
        cin>>a>>b>>c;
        a--, b--;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    for(auto it : graph[0]){
        pq.push({-it.second, it.first});
    }

    visited[0] = true;

    while(!pq.empty()){
        pair<int, int> here = pq.top();
        pq.pop();

        if(visited[here.second]) continue;
        visited[here.second] = true;
        ans -= here.first;

        for(auto next : graph[here.second]){
            pq.push({-next.second, next.first});
        }
    }

    cout<<ans<<"\n";
    return 0;
}