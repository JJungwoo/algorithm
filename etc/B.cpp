/*
같은 면적의 사각형으로 만들어야 함.

#include <cstdio>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int t, ch = 0;
	scanf("%d", &t);
	while (t--) {
		int n;
		int arr[10001] = { 0, };
		scanf("%d", &n);
		for (int i = 0; i < n*4; i++) {
			scanf("%d", &arr[i]);
		}
		sort(arr, arr+n*4);
		for(int i=0;i<n*4;i++)
			printf("%d: %d\n", i, arr[i]);
		for (int i = 1; i < n*4; i+=2) {
			if (arr[i] == arr[i - 1]) ch = 0;
			else ch = 1;
		}

		if (ch == 1) printf("NO\n");
		else printf("YES\n");
	}

	return 0;
}
*/