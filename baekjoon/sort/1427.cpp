/*
[boj] 1427. 소트인사이드
https://www.acmicpc.net/problem/1427
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int narr[10];
int main()
{
    io;
	string input;
	cin >> input;
	//sort(input.begin(), input.end(), greater<char>());
	for(char c : input) {
		narr[c-'0']++;
	}
	for(int i=9;i>=0;i--) {
		for(int j=0;j<narr[i];j++) {
			cout<<i;
		}
	}
	cout<<"\n";
	//cout << input << "\n";
    return 0;
}
