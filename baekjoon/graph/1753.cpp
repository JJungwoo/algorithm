/*
[boj] 1753. 최단 경로
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int INF = 1e9;
int V, E, K;
int dist[20001];
struct obj {
	int target, value;
	bool operator < (const obj t) const {
		return value > t.value;
	}
};
vector<obj> spot[20001];
void dijkstra() {
	priority_queue<obj> q;
	q.push({ K, 0 });
	dist[K] = 0;
	while (!q.empty()) {
		int now = q.top().target, value = q.top().value;
		q.pop();
		if (dist[now] < value) {
			continue;
		}
		for (int i = 0; i < spot[now].size(); i++) {
			int next = spot[now][i].target;
			int nvalue = spot[now][i].value + value;
			if (dist[next] > nvalue) {
				dist[next] = nvalue;
				q.push({ next, nvalue });
			}
		}
	}
}
int main()
{
	io;
	cin >> V >> E >> K;
	K--;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		spot[u].push_back({ v,w });
	}
	fill(dist, dist + V, INF);
	dijkstra();
	for(int i=0;i<V;i++){
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}
	return 0;
}