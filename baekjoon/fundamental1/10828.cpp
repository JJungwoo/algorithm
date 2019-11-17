/*
[BOJ] 10828. Ω∫≈√
https://www.acmicpc.net/problem/10828
*/
/*
#include <cstdio>
#include <stack>
#include <string.h>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	int n;
	stack<int> st;
	scanf("%d", &n);
	while (n--) {
		char tmp[10] = { '\0', };
		scanf("%s", &tmp);
		if (!strcmp("push", tmp)) {
			int val;
			scanf("%d", &val);
			st.push(val);
		}
		else if (!strcmp("pop", tmp)) {
			if (!st.empty()) {
				printf("%d\n", st.top());
				st.pop();
			}
			else printf("-1\n");
		}
		else if (!strcmp("size", tmp)) printf("%d\n", st.size());
		else if (!strcmp("empty", tmp))	printf("%d\n", st.empty());
		else if (!strcmp("top", tmp)) {
			if (!st.empty()) printf("%d\n", st.top());
			else printf("-1\n");
		}
	}
	return 0;
}
*/