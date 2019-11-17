/*
[BOJ] 9613. GCD гу
https://www.acmicpc.net/problem/9613
*/
/*
#include <cstdio>
using namespace std;
typedef long long ll;

int gcd(int a, int b) {
	if (b == 0) return a;
	else gcd(b, a % b);
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		int arr[101] = { 0, };
		int n;
		ll ans = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		for (int i = 0; i < n-1; i++) {
			for (int j = i + 1; j < n; j++) {
				ans += gcd(arr[i], arr[j]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
*/