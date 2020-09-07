#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s) {
	int answer = s.length();
	int slen = s.length();

	if (slen == 1)
		return 1;

	for (int i = 1; i <= slen / 2; i++) { // 비교할 문자
		int count = 1;
		string tmp = s.substr(0, i);
		string cmp, cp;

		for (int j = i; j < slen; j += i) {
			cmp = s.substr(j, i);
			int idx = j;
			if (!tmp.compare(cmp)) {
				count++;
				cout << "cmp: " << cmp << "\n";
			}
			else {
				if (count == 1) {
					cp += tmp;
					tmp = cmp;
				}
				else {
					cp = cp + to_string(count) + tmp;
					tmp = cmp;
					count = 1;
				}
			}
			if (i + j >= s.length()) {
				if (count != 1) {
					cp = cp + to_string(count) + tmp;
					break;
				}
				else {
					cp = cp + s.substr(j);
					break;
				}
			}
		}
		answer = (answer > cp.length()) ? cp.length() : answer;
	}
	return answer;
}


/*
#include <bits/stdc++.h>
using namespace std;

int f(int n) {
	if (n == 1) return 0;

	int ret = 0;
	while (n) ret++, n /= 10;
	return ret;
}
int solution(string s) {
	int answer = s.size(), n = s.size();
	unordered_set<string> S;

	for (int i = 1; i * 2 <= n; ++i) {
		S.clear();
		int j, len = 0, cnt = 1;
		string prv = s.substr(0, i);
		S.insert(prv);

		for (j = i; j < n; j += i) {
			if (S.find(s.substr(j, i)) != S.end()) ++cnt;
			else {
				len += f(cnt) + i;
				S.erase(prv);
				S.insert(prv = s.substr(j, i));
				cnt = 1;
			}
		}

		len += cnt > 1 ? f(cnt) + i : n - j + i;
		answer = min(answer, len);
	}
	return answer;
}

*/