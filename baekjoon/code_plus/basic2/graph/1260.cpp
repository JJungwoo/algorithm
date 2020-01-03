/*
[BOJ] 1260. DFS와 BFS
입력받은 그래프 결과를 dfs와 bfs로 출력하는 문제이다.
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n,m,s;
vector<int> map[10001];
bool visited[10001];

void printDFS(int v){
    visited[v] = true;
    cout<<v<<" ";
    for(int i=0;i<map[v].size();i++){
        int k = map[v][i];
        if(!visited[k])
            printDFS(k);
    }
}

void printBFS(int v){
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        cout<<tmp<<" ";
        for(int i=0;i<map[tmp].size();i++){
            int k = map[tmp][i];
            if(!visited[k]){
                visited[k] = true;
                q.push(k);
            }
        }
    }
}

int main()
{
    io;
    cin>>n>>m>>s;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        map[a].push_back(b);
        map[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        sort(map[i].begin(), map[i].end());
    }
    visited[s] = true;
    printDFS(s);
    memset(visited, 0, sizeof(visited));
    cout<<"\n";
    visited[s] = true;
    printBFS(s);

    return 0;
}