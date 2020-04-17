/*
[boj] 7662. 이중 우선순위 큐
동일한 정수가 입력될 수 있다;;
*/

#include <iostream>
#include <set>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int t, n;
int main()
{
	io;
	cin >> t;
	while (t--) {
		multiset<int> s;
		cin >> n;
		for (int i = 0; i < n; i++) {
			char cmd; cin >> cmd;
			int value; cin >> value;
			if(cmd == 'I') s.insert(value);
			else if (cmd == 'D' && !s.empty()) {
				if (value == 1) {
					s.erase(--s.end());
				}
				else {
					s.erase(s.begin());
				}
			}			
		}

		if (s.size() == 0) cout << "EMPTY\n";
		else {
			auto a = s.begin(), b = --s.end();
			cout << *b << " " << *a << "\n";
		}
	}

	return 0;
}