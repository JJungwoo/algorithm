/*
baekjoon 1874번 스택 수열
*/
/*
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int n, seq[100001], cnt = 1;
stack<int> st;
vector<char> answer;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> seq[i];
	for (int i = 0; i < n; i++) {
		if (st.empty() || st.top() != seq[i]) {
			while (true) {
				if (cnt > n) {
					puts("NO"); return 0;
				}
				st.push(cnt++);
				answer.push_back('+');
				if (st.top() == seq[i]) {
					st.pop();
					answer.push_back('-'); break;
				}
			}
		}
		else if (st.top() == seq[i]) {
			st.pop(); answer.push_back('-');
		}
	}

	for (auto it : answer)
		cout << it << endl;
	
	return 0;
}
*/