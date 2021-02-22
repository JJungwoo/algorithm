/*
[boj] 1629. 곱셈
https://www.acmicpc.net/problem/1629
*/
#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    io;
	long A, B, C, ans = 1;
	cin >> A >> B >> C;
	while(B > 0) {
		if(B % 2 != 0) {
			ans *= A;
			ans %= C;
		}
		A *= A;
		A %= C;
		B /= 2;
	}
	cout<<ans<<"\n";
    return 0;
}
