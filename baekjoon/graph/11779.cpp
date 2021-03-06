/*
[boj] 11779. 최소비용 구하기2
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int INF = 1e9;
int n, m, start, endspot;
struct obj {
	int city, cost, way;
	bool operator < (obj t) const {
		return cost > t.cost;
	}
	vector<int> load;
};
vector<obj> v[1001];
int dist[1001];
obj dijkstra() {
	priority_queue<obj> pq;
	pq.push({ start, 0, 1 });
	dist[start] = 0;
	while (!pq.empty()) {
		int now = pq.top().city, cost = pq.top().cost, way = pq.top().way;
		vector<int> tmp = pq.top().load;
		tmp.push_back(now + 1);
		pq.pop();
		if (now == endspot) {
			return { 0,0,way,tmp };
		}
		if (cost > dist[now]) continue;
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].city, ncost = v[now][i].cost + cost;
			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push({ next, ncost, way + 1, tmp });
			}
		}
	}
}
int main()
{
	io;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		a--, b--;
		v[a].push_back({ b, cost });
	}
	cin >> start >> endspot;
	start--, endspot--;
	fill(dist, dist + n, INF);
	obj tmp = dijkstra();
	cout << dist[endspot] << "\n";
	cout << tmp.way << "\n";
	for (int i = 0; i < tmp.load.size(); i++) {
		cout << tmp.load[i] << " ";
	}
	cout << "\n";
	return 0;
}

