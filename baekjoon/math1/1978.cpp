/*
[BOJ] 1978. �Ҽ� ã��
https://www.acmicpc.net/problem/1978
*

#include <cstdio>
#include <math.h>
using namespace std;

int main()
{
	int prime[100] = { 0, };
	int n, cnt = 0, i = 0;
	scanf("%d", &n);
	while (cnt > n) {
		if (i % 2 == 0)
			continue;
		sqrt(n);
		i++;
	}

	return 0;
}
*/