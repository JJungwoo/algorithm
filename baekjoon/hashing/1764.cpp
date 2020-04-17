/*
[boj] 1764. 듣보잡
*/

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

map<string, int> mp;
int n, m;
string tmp;
vector<string> ans;

int main()
{
	io;
	cin >> n >> m;
	while (n--) {
		cin >> tmp;
		mp[tmp]++;
	}

	while (m--) {
		cin >> tmp;
		mp[tmp]++;
	}

	for (auto it : mp) {
		if (it.second >= 2) {
			ans.push_back(it.first);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (auto it : ans) {
		cout << it << "\n";
	}
	return 0;
}

/*
#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int n, m;
multiset<string> nohear, nosee;
vector<string> ans;
int main()
{
	io;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		nohear.insert(tmp);
	}
	for (int i = 0; i < m; i++) {
		string tmp;
		cin >> tmp;
		auto it = nohear.find(tmp);
		if (it != nohear.end()) {
			ans.push_back(*it);
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}
*/