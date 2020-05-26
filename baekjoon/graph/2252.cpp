/*
[boj] 2252. 줄 세우기 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, m;
vector<int> v[32000], ans;
bool visited[32000];
void dfs(int start){
    visited[start] = true;

    for(int it : v[start]){
        if(visited[it]) continue;
        dfs(it);
    }
    ans.push_back(start);
}
int main()
{
    io;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        a--,b--;
        v[a].push_back(b);
    }

    for(int i=0;i<n;i++){
        if(visited[i]) continue;
        dfs(i);
    }
    reverse(ans.begin(), ans.end());
    for(auto it : ans){
        cout<<it+1<<" ";
    }
    cout<<"\n";
    return 0;
}