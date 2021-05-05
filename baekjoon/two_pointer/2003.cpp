/*
[boj] 2003. 수들의 합 2
https://www.acmicpc.net/problem/2003
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define MAX_SIZE 10001

int main()
{
    io;
	int n, m, i, std = 0, ans = 0, cnt = 0;
	int A[MAX_SIZE] = { 0, };

	cin >> n >> m;
	
	for (i = 0; i < n; i++) {
		cin >> A[i];
	}

	for (i = 0; i < n; i++) {
		std = A[i];
		cnt = i+1;
		while (std < m) {
			if (cnt >= n)
				break;
			std += A[cnt];
			cnt++;
		}
		if (std == m) 
			ans++;
		
		std = 0;
	}
	
	cout << ans << endl;
	return 0;
}