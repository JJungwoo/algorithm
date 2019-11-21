/*
Online Judge 12086. Potentiometers.
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3238
*/

#include <iostream>
#include <string>
using namespace std;

int n;
int arr[200001];
int tree[200001];

void update(int i, int val) {
	while (i <= n) {
		tree[i] += val;
		i += (i & - i);
	}
}

int sum(int i) {
	int ret = 0;
	while (i > 0) {
		ret += tree[i];
		i -= (i & -i);
	}
	return ret;
}

int range_sum(int l, int r) {
	return sum(r) - sum(l - 1);
}

int main()
{
	int tcase = 0;
	while (cin >> n) {
		if (n == 0) break;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			update(i, arr[i]);
		}
		if (tcase != 0) cout << "\n";
		cout << "Case " << ++tcase << ":\n";
		string a;
		int b, c;
		while (cin >> a) {
			if (a[0] == 'E') {
				break;
			}
			else if (a[0] == 'S') {
				cin >> b >> c;
				int ret = c - arr[b];
				update(b, ret);
			}
			else {
				cin >> b >> c;
				if (b == c)
					cout << sum(b) << "\n";
				else 
					cout<<range_sum(b, c)<<"\n";
			}
		}
	}
	return 0;
}
