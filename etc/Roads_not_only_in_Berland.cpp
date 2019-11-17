/*
#include <iostream>
#include <vector>
using namespace std;

struct union_find {
	vector<int> parent;
	union_find(int n) : parent(n) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int v) {
		if (parent[v] == v) return v;
		return find(parent[v]);
	}

	void merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u != v)
			parent[u] = v;
	}
};

int main()
{
	int n;
	cin >> n;
	union_find uf(n);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		uf.merge(a, b);
	}

	return 0;
}

*/