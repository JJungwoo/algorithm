/*
[BOJ] 1992¹ø: ÄõµåÆ®¸®
https://debuglog.tistory.com/95
https://github.com/blisstoner/BOJ/blob/master/1992.cpp
*/
/*
#include <stdio.h>
#include <iostream>
#include <string>
#pragma warning(disable:4996)
using namespace std;
char pic[64][64];
int N;

bool isAll0(int x, int y, int sz) {
	for (int i = x; i < x + sz; i++) {
		for (int j = y; j < y + sz; j++) {
			if (pic[i][j] == '1')
				return false;
		}
	}
	return true;
}

bool isAll1(int x, int y, int sz) {
	for (int i = x; i < x + sz; i++) {
		for (int j = y; j < y + sz; j++) {
			if (pic[i][j] == '0')
				return false;
		}
	}
	return true;
}

string quadtree(int x, int y, int sz) {
	if (isAll0(x, y, sz))
		return "0";
	if (isAll1(x, y, sz))
		return "1";
	return "(" + quadtree(x, y, sz / 2) + quadtree(x, y + sz / 2, sz / 2) + quadtree(x + sz / 2, y, sz / 2) + quadtree(x + sz / 2, y + sz / 2, sz / 2) + ")";
}
int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%s", pic[i]);
	cout << quadtree(0, 0, N);
	return 0;
}
*/

/*
#include <iostream>

#pragma warning(disable:4996)

using namespace std;

int N;
int picture[64][64];

void find(int n, int x, int y)
{
	if (n == 1) {
		printf("%d", picture[y][x]);
		return;
	}

	bool same = true;
	for (int i = y; i < y + n; i++) 
	{
		if (!same)break;
		for (int j = x;  j < x + n; j++)
		{
			if (picture[y][x] != picture[i][j])
			{
				same = false;
				break;
			}
		}
	}

	if (same) {
		printf("%d", picture[y][x]);
		return;
	}
	
	printf("(");
	find(n / 2, x, y);
	find(n / 2, x + n / 2, y);
	find(n / 2, x, y + n / 2);
	find(n / 2, x + n / 2, y + n / 2);
	printf(")");
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &picture[i][j]);
		}
	}

	find(N, 0, 0);

	return 0;
}
*/