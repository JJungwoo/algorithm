/*
[boj] 1766. 문제집 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, m;
vector<int> seq[32000];
priority_queue<int> ans;
int visited[32000];
int main()
{
    io;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        a--, b--;
        seq[a].push_back(b);
        visited[b]++;
    }

    for(int i=0;i<n;i++){
        if(visited[i]) continue;
        ans.push(-i);
    }

    while(!ans.empty()){
        int here = -ans.top();
        ans.pop();
        cout<<here + 1<<" ";
        for(auto it : seq[here]){
            visited[it]--;
            if(visited[it]) continue;
            ans.push(-it);
        }
    }
    cout<<"\n";
    
    return 0;
}