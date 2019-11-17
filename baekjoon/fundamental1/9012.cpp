/*
[BOJ] 9012. °ýÈ£
https://www.acmicpc.net/problem/9012
*/
/*
#include <cstdio>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	getchar();
	while (t--) {
		int st = 0, fch = 0;
		char tmp = NULL;
		while (scanf("%c", &tmp)) {
			if (tmp == '\n') break;
			else if (tmp == '(') st++;
			else if (tmp == ')') st--;
			if (st < 0) fch = 1;
		}
		if (st == 0 && fch == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
*/