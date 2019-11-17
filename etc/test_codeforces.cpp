/*

#include <iostream>
#include <vector>

using namespace std;

struct NaiveDisjointSet {
	vector<int> parent;
	NaiveDisjointSet(int n) : parent(n) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int u) const {
		if (u == parent[u]) return u;
		return find(parent[u]);
	}

	void merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) return;
		parent[u] = v;
	}
};

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	NaiveDisjointSet nds(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (a == 0)
			nds.merge(b, c);
		else
			if (nds.find(b) == nds.find(c)) printf("YES\n"); 
			else printf("NO\n");
	}


	return 0;
}

*/