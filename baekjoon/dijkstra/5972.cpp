/*
[boj] 5972. 택배 배송
https://www.acmicpc.net/problem/5972
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int INF = 1e9;
int dijstra(vector<vector<pair<int, int>>> &v, int n, int m) {
    priority_queue<pair<int, int>> pq;
    vector<int> path(n+1, INF);
    pq.push({0, 1});
    path[1] = 0;
    while(!pq.empty()) {
        int cur = pq.top().second; 
        int cost = -pq.top().first;
        pq.pop();
        if (cur == n) {
            return cost;
        }
        for(auto it : v[cur]) {
            int next = it.first;
            int nextcost = it.second;
            if (path[next] > path[cur] + nextcost) {
                path[next] = path[cur] + nextcost;
                pq.push({-path[next], next});
            }
        }
    }
    return -1;
}
int main() 
{
    io;
    int N, M; cin >> N >> M;
    vector<vector<pair<int, int>>> v(N+1);
    for(int i=0;i<M;i++) {
        int A_i, B_i, C_i; cin >> A_i >> B_i >> C_i;
        v[A_i].push_back({B_i, C_i});
        v[B_i].push_back({A_i, C_i});
    }
    cout<<dijstra(v, N, M)<<"\n";
    return 0;
}
