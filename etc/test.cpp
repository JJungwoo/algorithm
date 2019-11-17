/*
#include <iostream>
using namespace std;

int N;
int col[15];
int result = 0;

bool promising(int i)
{
	for (int j = 0; j<i; j++)
	{
		// 새로운 퀸과 기존의 퀸이 같은 행에 있거나 대각선에 있을 경우
		if (col[j] == col[i] || abs(col[i] - col[j]) == (i - j))
			return false;
	}
	return true;
}
void solve(int i)
{
	if (i == N)
		result += 1;
	else
	{
		for (int j = 0; j<N; j++)
		{
			col[i] = j;
			if (promising(i))
				solve(i + 1);
		}
	}
}


int main()
{
	int T;
	cin >> T;
	for (int tcase = 1; tcase <= T; tcase++) {
		result = 0;
		memset(col, 0, 15);
		cin >> N;
		solve(0);
		cout << "#" << tcase << " " << ans << endl;
	}

	return 0;
}

*/