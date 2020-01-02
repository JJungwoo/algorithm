/*
[BOJ] 13023. ABCDE
무방향 그래프에서 5개 이상의 연결이 되는지 확인하는 문제로 dfs를 통해 간단히 해결할 수 있다.
*/
#include <iostream>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, m;
vector<int> re[2001];
bool visited[2001];
int ans;

void dfs(int v, int depth)
{
    if(depth > 3){
        ans = 1;
        return;
    }
    visited[v] = true;
    for(int i=0;i<re[v].size();i++){
        int k = re[v][i];
        if(!visited[k])
            dfs(k, depth + 1);
    }
}

int main()
{
    io;
    cin>>n>>m; 
    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        re[a].push_back(b);      
        re[b].push_back(a);  
    }

    for(int i=0;i<n;i++){
        memset(visited, 0, sizeof(visited));
        dfs(i, 0);
        if (ans == 1) break;
    }
    cout<<ans<<"\n";

    return 0;
}