/*
[BOJ] 1212. 8진수 2진수
https://www.acmicpc.net/problem/1212
*/
/*
#include <iostream>
using namespace std;

int main()
{
	int i = -1, ch = 0;
	char n[333335] = { '\0', };
	scanf("%s", &n);
	while (n[++i]) {
		int ans = 0, tmp = n[i] - '0';
		for (int j = 2; j >= 0; j--) {
			ans = ((tmp >> j) & 1);
			if (ans) ch = 1;
			if (ch) printf("%d", ans);
		}
	}
	if (!ch)
		printf("0");
	printf("\n");
	return 0;
}
*/