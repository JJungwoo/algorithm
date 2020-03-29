/*
[boj] 1717. 집합의 표현
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, m;
int parent[1000001];
void init() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}
int find(int p) {
	if (parent[p] == p) return p;
	else return parent[p] = find(parent[p]);
}

void uni(int p, int q) {
	p = find(p);
	q = find(q);
	if (q == p) return;
	parent[p] = q;
}
int main()
{
	io;
	cin >> n >> m;
	init();
	for (int i = 0; i < m; i++) {
		int op, a, b;
		cin >> op >> a >> b;
		if (!op) {
			uni(a, b);
		}
		else {
			int atmp = find(a), btmp = find(b);
			if (atmp == btmp) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	

	return 0;
}