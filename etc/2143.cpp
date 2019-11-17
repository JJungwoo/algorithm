/*
BOJ 2143. 두 배열의 합

#include <iostream>

using namespace std;

typedef long long ll;

ll T;
int n, m;
int narr[1001];
int marr[1001];

bool optimize(ll mid) {
	for(int i=0;i<)
}

void decision()
{
	ll lo = -1e9, hi = 1e9;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		if (optimize(mid))
			mid = hi;
		else
			mid = lo;
	}
	cout << hi << endl;
}

int main() {
	cin >> T >> n;
	for (int i = 0; i < n; i++)
		cin >> narr[i];
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> marr[i];

	decision();

	return 0;
}
*/