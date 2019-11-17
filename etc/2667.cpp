/*
baekjoon 2667번 단지번호붙이기.
*/
/*
#include <iostream>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
int N;
int map[25][25];
int visit_cnt[50];

bool search(int x, int y, int gcnt)
{
	if (x + 1 >= N && x - 1 < 0 && y + 1 >= N && y - 1 < 0)
		return false;

	if (map[x][y] != 1)
		return false;

	map[x][y] = gcnt;
	visit_cnt[gcnt] += 1;
	
	search(x + 1, y, gcnt);
	search(x - 1, y, gcnt);
	search(x, y + 1, gcnt);
	search(x, y - 1, gcnt);

	return true;
}

int main()
{
	int gcnt = 2;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%1d", &map[i][j]);

	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			if(search(i, j, gcnt))
				gcnt++;
		}
	}
	
	cout << gcnt-2 << endl;
	
	sort(visit_cnt, visit_cnt + gcnt);

	for (int i = 0; i < gcnt; i++) {
		if (visit_cnt[i] != 0)
			cout << visit_cnt[i] << endl;
	}

	return 0;
}
*/