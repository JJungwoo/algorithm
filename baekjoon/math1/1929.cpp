/*
[BOJ] 1929. 소수 구하기
https://www.acmicpc.net/problem/1929
*

#include <iostream>
using namespace std;

int factor[1000001];

void eratosthenes(int n) {
	factor[0] = factor[1] = -1;
	for (int i = 2; i <= n; ++i) 
		factor[i] = i;
	int sqrtn = int(sqrt(n));
	for (int i = 2; i <= sqrtn; ++i) {
		if (factor[i] == i) {
			for (int j = i*i; j <= n; j += i)
				if (factor[j] == j)
					factor[j] = i;
		}
	}
}

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);
	eratosthenes(n);
	for (int i = m; i < n; i++)
		printf("%d\n", factor[i]);

	return 0;
}
*/