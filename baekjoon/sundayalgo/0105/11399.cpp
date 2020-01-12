/*
[BOJ] 11399. ATM
*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    io;
    int N, i, j, tmp, ans = 0;
	int np[1000] = { 0, };

	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> np[i];
	}

	for (i = 1; i < N; i++) {
		for (j = 0; j < i; j++) {
			if (np[j] > np[i]) {
				tmp = np[j];
				np[j] = np[i];
				np[i] = tmp;
			}
		}
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j <= i; j++) {
			ans += np[j];
		}
	}
	
	cout << ans << endl;


    return 0;
}