/*
[boj] 1719. 택배 
https://www.acmicpc.net/problem/1719
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int INF = 1e8;
/*
void dijkstra(int pos, int n, vector<vector<pair<int, int>>> &graph) {
    vector<int> path(n, INF), ans;
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>> pq;
    path[pos] = 0;
    visited[pos] = true;
    pq.push({0, pos});

    while (!pq.empty()) {
        int cur = pq.top().second; 
        pq.pop();
        for(auto it : graph[cur]) {
            int next = it.first;
            int value = -it.second;
            if (visited[next]) continue;
            
            if (path[next] > path[cur] + value) {
                visited[next] = true;
                path[next] = path[cur] + value;
                pq.push({-path[next], next});
                ans.push_back(next);
            }
        }
    }

    for(auto it : ans) {
        cout << it << " ";
    }
    cout<<"\n";
}
int main() 
{
    io;
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);
    for (int i=0;i<m;i++) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }  

    for (int i=0;i<n;i++) {
        cout<<i<<"\n";
        dijkstra(i, n, graph);
    }

    return 0;
}
*/

int main() 
{
    io;
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, INF));
    vector<vector<int>> path(n, vector<int>(n));
    for (int i=0;i<m;i++) {
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        graph[a][b] = c;
        graph[b][a] = c;
        path[a][b] = b;
        path[b][a] = a;
    }  

    for (int z=0;z<n;z++) {
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (graph[i][j] > graph[i][z] + graph[z][j]) {
                    path[i][j] = path[i][z];
                    graph[i][j] = graph[i][z] + graph[z][j];
                }
            }
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (i == j) cout << "- ";
            else cout << path[i][j] + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}
