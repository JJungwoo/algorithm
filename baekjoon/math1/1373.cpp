/*
[BOJ] 1373. 2진수 8진수
https://www.acmicpc.net/problem/1373
*/
/*
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
int main()
{
	char n[1000001] = { '\0', };
	queue<int> q;
	int i = 0, ans = 0;
	scanf("%s", &n);
	for (int i = 0; n[i]; i++)
		q.push(n[i] - '0');
	if (i = q.size() % 3) i -= 1;
	else i = 2;
	while (!q.empty()) {
		ans += q.front() * pow(2, i--);
		q.pop();
		if (i < 0) {
			printf("%d", ans);
			ans = 0;
			i = 2;
		}
	}
	return 0;
}
*/