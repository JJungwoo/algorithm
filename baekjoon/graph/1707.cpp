/*
[boj] 1707. 이분 그래프 
https://www.acmicpc.net/problem/1707
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int K, V, E;
int visited[20001];
vector<int> v[20001];
bool bfs(int idx, int color) {
    queue<int> q;
    visited[idx] = color;
    q.push(idx);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        color = visited[cur];
        for(auto next : v[cur]) {
            if(visited[next] == color) return false;
            else if(visited[next] != 0) continue;
            visited[next] = -color;
            q.push(next);
        }
    }
    return true;
}
int main() 
{
    io;
    cin >> K;
    while(K--) {
        bool chk = false;
        cin >> V >> E;
        memset(visited, 0, sizeof(visited));
        for(int i=0;i<=V;i++) {
            v[i].clear();
        }
        for(int i=0;i<E;i++) {
            int A, B;
            cin >> A >> B;
            v[A].push_back(B);
            v[B].push_back(A);
        }
        for(int i=1;i<=V;i++)
            if(visited[i] == 0) {
                chk = bfs(i, 1);
                if(!chk) break;
            }
        if(chk) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}