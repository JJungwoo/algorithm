/*
[BOJ] 2042. 구간 합 구하기
https://www.acmicpc.net/problem/2042
*/
#include <iostream>
using namespace std;

long long arr[1000101];
long long tree[4000001];
int n, m, k;

void update(int i, long long val) {
	while (i <= n) {
		tree[i] += val;
		i += (i & -i);
	}
}

long long sum(int i) {
	long long ret = 0;
	while (i > 0) {
		ret += tree[i];
		i -= (i & -i);
	}
	return ret;
}

long long range_sum(int l, int r) {
	return sum(r) - sum(l - 1);
}

int main_2042()
{
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		update(i, arr[i]);
	}

	for (int i = 0; i < m + k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			long long diff = c - arr[b];
			arr[b] = c;
			update(b, diff);
		}
		else {
			cout << range_sum(b, c) << "\n";
		}
	}

	return 0;
}
