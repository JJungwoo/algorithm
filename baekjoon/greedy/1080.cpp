/*
[boj] 1931. 회의실배정
*/
#include <cstdio>
#pragma warning(disable:4996)
using namespace std;
int n, m, ans;
int a[51][51], b[51][51];
bool success;
void function(int x, int y) {
	for (int i = x; i < x+3; i++) {
		for (int j = y; j < y + 3; j++) {
			if (a[i][j] == 0) a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
}
bool check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != b[i][j]) return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &b[i][j]);
		}
	}
	if (n < 3 || m < 3) {
		if (check()) {
			success = true;
		}
	}
	else {
		for (int i = 0; i <= n - 3; i++) {
			for (int j = 0; j <= m - 3; j++) {
				if (a[i][j] != b[i][j]) {
					function(i, j);
					ans++;
				}
				if (check()) {
					success = true;
					break;
				}
			}
		}
	}
	if (!success) ans = -1;
	printf("%d\n", ans);
	return 0;
}