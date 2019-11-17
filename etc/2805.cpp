/*
[BOJ] 2805 나무 자르기
https://www.acmicpc.net/problem/2805
*/
/*
#include <iostream>
using namespace std;
typedef long long ll;

ll N, M;
ll wood[1000001];

bool optimize(ll mid) {
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		ans += (wood[i] - mid);
	}
	if (ans >= M) 
		return true;
	return false;
}

ll decision() {
	ll lo = 0, hi = 10;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		if (optimize(mid))
			lo = mid;
		else 
			hi = mid;
	}
	return hi;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> wood[i];
	}
	cout << decision() << endl;
	return 0;
}
*/
