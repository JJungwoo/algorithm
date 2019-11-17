/*
test case 3 time limit

#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int n, ans = 1, ch = 0;
	int a[40000] = { 0, };
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 1; i < a[0]; i++) {
		if (a[0] % i == 0) {
			for (int j = 1; j < n; j++) {
				if (a[j] % i == 0)
					ch++;
				else
					break;
			}
			if (ch == n - 1)
			{
				ans++;
				ch = 0;
			}
		}
	}
	
	printf("%d\n", ans);
	return 0;
}
*/