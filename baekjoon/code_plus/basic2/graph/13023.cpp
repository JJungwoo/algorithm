/*
[BOJ] 13023. ABCDE
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
    if(depth > 4){
        ans = 1;
        return;
    }
    visited[v] = true;
    for(int i=0;i<re[v].size();i++){
        int k = re[v][i];
        if(!visited[v])
            dfs(k, depth + 1);
    }
    visited[v] = false;
}

int main()
{
    cin>>n>>m; 
    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        re[a].push_back(b);      
        re[b].push_back(a);  
    }

    for(int i=0;i<n;i++){
        memset(visited, 0, sizeof(visited));
        if(!visited[i])
            dfs(i, 0);
        if (ans == 1) break;
    }
    cout<<ans<<"\n";

    return 0;
}