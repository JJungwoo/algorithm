/*
[boj] 1339. 단어 수학
2
AAA
AAA
1998
*/
/*
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, ans, tcnt;
string msg[10];
bool check[26];
int ialphabet[26];
vector<char> alphabet;
int a[11], b[11];
void solve(int cnt) {
	if (10-cnt == tcnt) {
		int total = 0;
		for (int i = 0; i < n; i++) {
			int size = msg[i].size();
			for (int j = 0, z = size-1; j < size; j++, z--) {
				//cout << msg[i][j]<<","<<ialpabet[msg[i][j] - 'A'] << "\n";
				total += (ialphabet[msg[i][j] - 'A'] * pow(10, z));
			}
		}
		if (ans < total) {
			ans = total;
		}
		return;
	}
	int size = alphabet.size();
	for (int i = 0; i < size; i++) {
		if (ialphabet[alphabet[i] - 'A']) continue;
		ialphabet[alphabet[i] - 'A'] = cnt - 1;
		solve(cnt - 1);
		ialphabet[alphabet[i] - 'A'] = 0;
	}
}
int main()
{
	io;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> msg[i];
		for (int j = 0; j < msg[i].size(); j++) {
			if (!check[msg[i][j] - 'A']) {
				check[msg[i][j] - 'A'] = true;
				alphabet.push_back(msg[i][j]);
				tcnt++;
			}
		}
	}
	int p = 0;
	for (int i = 0; i < 10; i++) a[i] = i;
	for (int i = 0; i < 10; i++) {
		cout << i << ":" << a[i] << "\n";
	}
	for (int i = 0; i < 26; i++) {
		if (check[i]) a[p++] = i + 'A';
	}
	sort(a, a + 10);
	for (int i = 0; i < 10; i++) {
		cout << i << ":" << a[i] << "\n";
	}
	//solve(10);
	cout << ans << "\n";
	return 0;
}
*/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
string msg[10];
int alphabet[26];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> msg[i];
		int size = msg[i].size();
		for (int j = 0, z = size - 1; j < size; j++, z--) {
			alphabet[msg[i][j] - 'A'] = msg[i][j] - 'A' * pow(10, z);
		}
	}
	sort(alphabet, alphabet + 26);
	return 0;
}