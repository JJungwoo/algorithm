/*
[boj] 1339. 단어 수학
2
AAA
AAA
1998
*/
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n;
string msg[10];
int alphabet[26];
bool cmp(int a, int b) {
	if(a > b) return true;
	else return false;
}
int main()
{
	io;
	cin >> n;
	//for (int i = 0; i < 26; i++) alphabet[i] = -1;
	for (int i = 0; i < n; i++) {
		cin >> msg[i];
		int size = msg[i].size();
		for (int j = 0, z = size - 1; j < size; j++, z--) {
			//if (alphabet[msg[i][j] - 'A'] == -1) {
				alphabet[msg[i][j] - 'A'] += pow(10, z);
			//}
		}
	}
	sort(alphabet, alphabet + 26, cmp);
	int ans = 0;
	for (int i = 9, idx = 0; i >= 0; i--, idx++) {
		if (alphabet[idx] != 0) {
			ans += (alphabet[idx] * i);
		}
	}
	cout << ans << "\n";
	return 0;
}