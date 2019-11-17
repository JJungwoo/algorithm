/*
[BOJ] 10799¹ø ¼è¸·´ë±â.
https://www.acmicpc.net/problem/10799
*/
/*
#include <cstdio>
#include <stack>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	char tmp = NULL;
	stack<char> iron;
	int ans = 0, laser = 0;
	while (scanf("%c", &tmp)) {
		if (tmp == '\n') break;
		if (tmp == '(') {
			iron.push(tmp);
			laser = 0;
		} else {
			if (tmp == ')') {
				iron.pop();
				if (!laser) ans += iron.size();
				else ans += 1;
				laser = 1;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
*/
