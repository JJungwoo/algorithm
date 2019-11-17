/*
[BOJ] 1114 통나무 자르기

#include <iostream>

using namespace std;
typedef long long ll;

ll L;
int K, C;
int cut_wood[10001];

bool optimize(ll mid) {
	for (int i = 0; i < K; i++) {
		if(abs(cut_wood[i] - L))

	}
}

void decision() {
	ll lo = 0, hi = 1e9;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		if (optimize(mid))
			lo = mid;
		else
			hi = mid;
	}
}

int main()
{
	cin >> L >> K >> C;
	for (int i = 0; i < K; i++) {
		cin >> cut_wood[i];
	}

	return 0;
}
*/


