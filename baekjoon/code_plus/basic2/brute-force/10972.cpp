/*
[BOJ] 10972. 다음 순열
*/
#include <iostream>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int MAX = 1e5;
int n;
int seq[MAX+1];
int visited[MAX+1];
int ans[MAX+1];

void dfs(int v){
    cout<<seq[v]<<" ";
    for(int i=0;i<n;i++){
        if(visited[i]) continue;
        if(i == v) continue;
        visited[i] = true;
        dfs(i);
        visited[i] = false;
    }
}

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++) seq[i] = i+1;
    //for(int i=0;i<n;i++) cin>>ans[i];
    for(int i=0;i<n;i++){
        if(!visited[i])
            dfs(i);
        memset(visited, 0, sizeof(visited));
        cout<<"\n";
    }


    return 0;
}