/*
[BOJ] 9935. 문자열 폭발
https://www.acmicpc.net/problem/9935
*/
// 문자열 사용
/*
#include <iostream>
#include <string>

using namespace std;
int main()
{
	string inStr, keyword, ans;
	cin >> inStr >> keyword;
	int str_len = inStr.length();
	int keyword_len = keyword.length() - 1;
	for (int i = 0; i < str_len; i++) {
		ans += inStr[i];
		bool check = true;
		int ans_len = ans.length() - 1;
		if (ans[ans_len] == keyword[keyword_len]) {
			for (int j = 0; j <= keyword_len; j++) {
				if (ans[ans_len - keyword_len + j] != keyword[j]) {
					check = false;
					break;
				}
			}
			if (check) 
				ans.erase(ans_len - keyword_len, keyword_len + 1);
		}
	}
	if (ans == "\0") cout << "FRULA\n";
	else cout << ans << "\n";

	return 0;
}
*/
// 스택 사용
// 참고 : https://swjeong.tistory.com/126
/*
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	

	return 0;
}
*/
