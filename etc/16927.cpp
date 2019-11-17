/*
[BOJ] 16927. 배열 돌리기2
https://www.acmicpc.net/problem/16927


#include <cstdio>

using namespace std;

typedef long long ll;

int main()
{
	int n, m;
	int arr[300][300] = { 0, };
	int ans_arr[300][300] = { 0, };
	ll r;

	scanf("%d %d %lld", &n, &m, &r);
	int rotate = (2 * m) + (2 * n) - 4;
	rotate = r % rotate;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		ans_arr[i][1] = arr[1][i];
	}

	// 4 + (5-1) + (4-1) + (5-2) = 14
	// 

	return 0;
}
*/
