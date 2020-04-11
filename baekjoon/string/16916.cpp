/*
[boj] 16916. 부분 문자열
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
vector<int> getPi(string p) {
	int m = (int)p.size(), j = 0;
	vector<int> pi(m, 0);
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}
vector<int> kmp(string s, string p) {
	vector<int> ans;
	auto pi = getPi(p);
	int n = (int)s.size(), m = (int)p.size(), j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	return ans;
}

int main()
{
	io;
	string s, p;
	cin >> s >> p;
	auto matched = kmp(s, p);
	cout << !matched.empty() << "\n";

	return 0;
}