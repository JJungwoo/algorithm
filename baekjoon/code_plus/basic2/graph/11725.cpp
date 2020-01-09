/*
[BOJ] 11725. 트리의 부모 찾기
1에서부터 연결된 노드들을 dfs로 하나하나 찾아가면 인접 그래프를 트리로 표현헐 수 있음.
*/
#include <iostream>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int MAX = 100000;
int n;
vector<int> adj[MAX+1];
int parent[MAX+1];
bool visited[MAX+1];

void dfs(int v){
    if(visited[v]) return;
    visited[v] = true;
    for(int next : adj[v]){
        if(!parent[next])
            parent[next] = v;
        dfs(next);
    }
}

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    for(int i=2;i<=n;i++){
        cout<<parent[i]<<"\n";
    }
    return 0;
}