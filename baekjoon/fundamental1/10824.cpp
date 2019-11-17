/*
[BOJ] 10824. ³× ¼ö
https://www.acmicpc.net/problem/10824
*/
/*
#include <cstdio>
using namespace std;
typedef long long ll;
int main() {

	ll a, b, c, d, tmp = 1;
	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
	while (tmp <= b) tmp *= 10;
	a *= tmp;
	tmp = 1;
	while (tmp <= d) tmp *= 10;
	c *= tmp;
	printf("%lld\n", a + b + c + d);

	return 0;
}
*/