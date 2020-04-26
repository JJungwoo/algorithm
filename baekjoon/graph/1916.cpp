/*
[boj] 1916. 최소비용 구하기
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

struct bus {
	int city, cost;
	bool operator < (const bus t) const { return cost > t.cost; }
};

int n, m, spoint, epoint;
int dist[1001];
vector<bus> v[1001];
const int INF = 1e9;

void dijkstra() {
	priority_queue<bus> pq;
	pq.push({ spoint, 0 });
	dist[spoint] = 0;
	while (!pq.empty()) {
		int now = pq.top().city, cost = pq.top().cost;
		pq.pop();
		if (dist[now] < cost) continue;
		for (auto k : v[now]) {
			int next = k.city, ncost = cost + k.cost;
			if (dist[next] > ncost) {
				dist[next] = ncost;
				pq.push({ next, ncost });
			}
		}
	}
}
int main()
{
	io;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a - 1].push_back({ b - 1, c });
	}
	cin >> spoint >> epoint;
	spoint--, epoint--;
	fill(dist, dist + n, INF);
	dijkstra();
	cout << dist[epoint] << '\n';
	return 0;
}
