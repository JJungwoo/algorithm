/*
baekjoon 2609�� �ִ������� �ּҰ����.
*/
/*
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int nn1, nn2, max_ans, min_ans, a, cnt = 1;
	cin >> nn1 >> nn2;
	if (nn1 == 0 || nn2 == 0)
	{
		cout << min_ans << endl;
		cout << max_ans << endl;
		return 0;
	}
	a = min(nn1, nn2);
	while (1) {
		if (nn1 % a == 0 && nn2 % a == 0) {
			min_ans = a;
			break;
		}
		a--;	
	}
	a = min_ans * cnt;
	while (1) {
		if (a % nn1 == 0 && a % nn2 == 0)
		{
			max_ans = a;
			break;
		}
		cnt++;
		a = min_ans * cnt;
	}

	cout << min_ans << endl;
	cout << max_ans << endl;

	return 0;
}
*/