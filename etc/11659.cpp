/*
BOJ 11659. 구간 합 구하기 4
*/
/*
#include <iostream>

using namespace std;

int n, m;
int seq[100001];
int partial[100100];
void partial_sum(int value) {
	for (int i = 1; i <= value; i++) {
		partial[i] = partial[i-1] + seq[i];
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&seq[i]);
	}
	partial[1] = seq[1];
	partial_sum(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", partial[y] - partial[x - 1]);
	}

	return 0;
}
*/