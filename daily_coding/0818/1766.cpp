/*
[boj] 1766. 문제집
https://www.acmicpc.net/problem/1766
*/

#include <iostream>
#include <vector>
#include <queue>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, m, a, b, visited[32001];
vector<int> relation[32001];
priority_queue<int> ans;
int main()
{
    io;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        relation[a-1].push_back(b-1);
        visited[b-1]++;
    }

    for(int i=0;i<n;i++){
        if(visited[i]) continue;
        ans.push(-i);
    }

    while(!ans.empty()) {
        int cur = -ans.top();
        ans.pop();
        cout<<cur + 1<<" ";
        for(auto it : relation[cur]) {
            visited[it]--;
            if(visited[it] == 0)
                ans.push(-it);
        }
    }

    return 0;
}

