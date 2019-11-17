/*
#include <cstdio>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);

	while (t--) {
		int arr[201] = { 0, }; 
		int n, ch = 0;
		scanf("%d", &n);
		scanf("%d", &arr[0]);
		if (n == 1) {
			printf("YES\n");
			continue;
		}
		for (int i = 1; i < n; i++) {
			scanf("%d", &arr[i]);
			if (arr[i] != arr[i - 1] + 1 && arr[i] != arr[i-1] - 1)
				ch++;
		}
		if (arr[0] != arr[n - 1] - 1 && arr[0] != arr[n - 1] + 1)
			ch++;
		if (ch >= 2) printf("NO\n");
		else printf("YES\n");
	}

	return 0;
}
*/