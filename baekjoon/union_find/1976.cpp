/*
[boj] 1976. 여행 가자
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, m;
int map[201][201];
int parent[201];
void init() {
	for (int i = 0; i < n; i++) {
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
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j]) {
				uni(i, j);
			}
		}
	}
	int input = -1;
	bool check = true;
	for (int i = 0; i < m; i++) {
		int tmp; cin >> tmp; tmp--;
		tmp = find(tmp);
		if (input != -1 && input != tmp) {
			check = false;
			break;
		}
		input = tmp;
	}
	if(check) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}