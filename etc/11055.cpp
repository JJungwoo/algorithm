/*
[BOJ] 11055. 가장 큰 증가 부분 수열
https://www.acmicpc.net/problem/11055
*/
/*
#include <iostream>

using namespace std;

int _lower_bound(int lo, int hi, int *tmp, int value) {
	
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (tmp[mid] >= value) hi = mid;
		else lo = mid + 1;
	}
	return hi;
}

int main()
{
	int n;
	int A[1001] = { 0, };
	int tmp[1001] = { 0, };
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> A[i];

	tmp[0] = A[0];
	
	int i = 1;
	int j = 0;

	while (i < n) {
		if (A[i] > tmp[j]) {
			tmp[j + 1] = A[i];
			j++;
		}
		else {
			int res = _lower_bound(0, j, tmp, A[i]);
			tmp[res - 1] = A[i];
		}
		i++;
	}
	cout << j + 1 << '\n';

	return 0;
}*/
