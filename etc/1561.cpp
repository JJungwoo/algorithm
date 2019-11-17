/*
baekjoon 1561�� ���� ����.
*/
/*
#include <iostream>
using namespace std;
typedef unsigned long long LL;
LL N;
int M;
int arr[10001];

bool decision(int mid)
{
	int sum = 0;
	for (int i = 0; i < M; i++)
	{
		int tmp = mid / arr[i] ;
		sum += tmp;
	}
	return mid == sum;
}

int optimize()
{
	int ans = 0;
	LL lo = 0, hi = 2e10 + 1;
	while (lo + 1 < hi) {
		LL mid = (lo + hi) / 2;
		if (decision(mid)) 
			lo = mid;
		else
			hi = mid;
	}
	for (int i = 0; i < M; i++)
		if (lo / arr[i] == 0)
			ans = i;
	return ans;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> arr[i];
	}
	cout << optimize() << endl;

	return 0;
}
*/
//
/*
�ݷ�
1987654321 2
15 14

-> 2�� ���;� �ϴµ� 1�� ���ɴϴ�
*/