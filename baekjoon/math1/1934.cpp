/*
[BOJ] 1934. 최소공배수
https://www.acmicpc.net/problem/1934
*/
/*
#include <cstdio>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else gcd(b, a % b);
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--) {
		int a, b, ans = 0;
		scanf("%d %d", &a, &b);
		ans = gcd(a, b);
		if (ans == 1) ans = a*b;
		else ans = a * b / ans;
		printf("%d\n", ans);
	}
	
	return 0;
}
*/