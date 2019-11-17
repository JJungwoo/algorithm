/*
[BOJ] 2578. ºù°í
https://www.acmicpc.net/problem/2578
*

#include <iostream>
using namespace std;

#define BINGO_SIZE 5
int arr[5][5] = { 0, };
int bingo[5][5] = { 0, };
int bingo_cnt;

void check_bingo(int ch) {
	for (int i = 0; i < BINGO_SIZE; i++) {
		for (int j = 0; j < BINGO_SIZE; j++) {
			if (arr[i][j] == ch) {
				bingo[i][j] = 1;
				if (bingo[i][j] != 0)
					dfs(i, j);
				return;
			}
		}
	}
}

void dfs(int y, int x) {



	if (y + 1 < BINGO_SIZE && x + 1 < BINGO_SIZE && y - 1 <= 0 && x - 1 <= 0)
	{
		dfs(y + 1, x);
	}

}

int main()
{
	for (int i = 0; i < BINGO_SIZE; i++) {
		for (int j = 0; j < BINGO_SIZE; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < BINGO_SIZE * BINGO_SIZE; i++) {
		int check;
		scanf("%d", &check);
		check_bingo(check);
	}

	for (int i = 0; i < BINGO_SIZE; i++) {
		for (int j = 0; j < BINGO_SIZE; j++) {
			if (bingo[i][j] != 0
				&& (i == 0 || j == 0 || i == 4 || j == 4))
				dfs(i, j);
		}
	}

	return 0;
}

*/