/*
[boj] 13913. 숨바꼭질 4
https://www.acmicpc.net/problem/13913
*/

#include <iostream>
#include <queue>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int dir[3] = { -1, 1, 2 };
int N, K;
int visited[100001], path[100001];
void bfs() {
    queue<int> q;
    q.push(N);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(cur == K) {
            break;
        }
        for(int i=0;i<3;i++) {
            int next = cur + dir[i];
            if(i == 2) next = cur * dir[i];
            if(next < 0 || next >= 100001) continue;
            if(visited[next]) continue;
            visited[next] = visited[cur] + 1;
            path[next] = cur;
            q.push(next);
        }
    }
}
int main() 
{
    io;
    cin >> N >> K;
    bfs();
    int idx = K;
    vector<int> ans;
    while(idx != N) {
        ans.push_back(idx);
        idx = path[idx];
    }
    ans.push_back(N);
    cout<<ans.size()-1<<"\n";
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i]<<" ";
    cout<<"\n";
    return 0;
}