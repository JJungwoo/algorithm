/*
[boj] 1003. 피보나치 함수
https://www.acmicpc.net/problem/1003
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main()
{
    io;
	int T; cin >> T;
	int zero[41] = {1, };
	int one[41] = {0, 1};

	for(int i=2;i<41;i++) {
		zero[i] = zero[i-1] + zero[i-2];
		one[i] = one[i-1] + one[i-2];
	}

	while(T--) {
		int N; cin >> N;
		cout<<zero[N]<<' '<<one[N]<<"\n";
	}
    return 0;
}
