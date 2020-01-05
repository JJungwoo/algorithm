/*
[BOJ] 16947. 서울 지하철 2호선
주어진 그래프에서 순환 그래프를 찾고 거기에 연결된 위치들 거리 값을 구하면 된다.
딱 봐도 union find 인 것 같은데..
먼저 순환되는 그래프를 찾는 방법으로 자신의 위치에서 자신의 위치로 돌아올 수 있다면 순환 그래프이다.
dfs로 순환 경로를 찾고 다음으로 bfs로 순환 경로에서 거리 값을 저장해준다.
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
vector<int> v[3001];
queue<int> q;
bool isCycle, visited[3001];
int way[3001];

void dfs(int x, int sx, int cnt){
    if(cnt >= 2 && x == sx){
        isCycle = true;
        return;
    }
    int len = v[x].size();
    for(int i=0;i<len;i++){
        int k = v[x][i];
        if(visited[k]) continue;
        if(cnt < 2 && sx == k) continue;
        visited[k] = true;
        dfs(k, sx, cnt + 1);
        visited[k] = false;
    }
}

void bfs(int a)
{
    q.push(a);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        int len = v[x].size();
        for(int i=0;i<len;i++){
            int k = v[x][i];
            if(visited[k]) continue;
            if(way[k] != 0) way[k] = way[x]+1;
            visited[k] = true;
            q.push(k);
        }
    }
}

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        int x, y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    memset(way, -1, sizeof(way));
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i, i, 0);
            if(isCycle) 
                way[i] = 0;
            isCycle = false;
            memset(visited, 0, sizeof(visited));
        }
    }
    for(int i=1;i<=n;i++){
        if(way[i] == 0)
            bfs(i);  
    }

    for(int i=1;i<=n;i++){
        cout<<way[i]<<" ";
    }
    cout<<"\n";
    return 0;
}