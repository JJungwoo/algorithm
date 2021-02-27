/*
[boj] 12919. A와 B 2
https://www.acmicpc.net/problem/12919
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
string S, T;
bool check;
void solve(string t) {
	if(t.empty() || check) return;
	if(!S.compare(t)) {
		check = true;
		return;
	}
	if(t.back() == 'A') {
		string tmp = t;
		tmp.pop_back();
		solve(tmp);
	}
	if(t.front() == 'B') {
		reverse(begin(t), end(t));
		t.pop_back();
		solve(t);
	}
}
int main()
{
    io;
	cin >> S >> T;
	solve(T);
	cout<<check<<"\n";
    return 0;
}
