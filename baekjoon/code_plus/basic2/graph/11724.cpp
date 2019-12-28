/*
[BOJ] 11724. 연결 요소의 개수
무방향 그래프에서 연결 요소의 개수를 구하기.
한 위치에서 다른 위치로 접근이 가능하면 연결된 그래프이다.
1. 단순 dfs로 연결 요소 찾기
2. union find로 연결 요소 찾기
dfs ref: https://rebas.kr/653, https://algorithm-nightmare.tistory.com/14
, https://penglog.tistory.com/51
bfs ref: https://hibee.tistory.com/143
https://wondy1128.tistory.com/133
*/
#include <iostream>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n,m;
vector<int> vmap[1001];
bool visited[1001];

void dfs(int pos)
{
    visited[pos] = true;
    for(int i=0;i<(int)vmap[pos].size();i++){
        int next = vmap[pos][i];
        if(!visited[next]) 
            dfs(next);
    }    
}

int main()
{
    io;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u, v;
        cin>>u>>v;
        vmap[u].push_back(v);
        vmap[v].push_back(u);
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt<<"\n";
    return 0;
}