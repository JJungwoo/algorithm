/*
BOJ 11660 구간 합 구하기 5
https://www.acmicpc.net/problem/11660


#include <iostream>

#pragma warning(disable:4996)
using namespace std;

int n, m;
int arr[1024][1024];

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
			arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
		}
	}

	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2; 
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d \n", arr[x2][y2] - arr[x2][y1 - 1] - arr[x1 - 1][y2] + arr[x1 - 1][y1 - 1]);
	}
		
	return 0;
}
*/
