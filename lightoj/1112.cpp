/*
Light OJ 1112. Curious Robin Hood
http://www.lightoj.com/volume_showproblem.php?problem=1112
*/
#include <iostream>
using namespace std;

int tree[100001];
int arr[100001];
int n, q;

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

void update(int i, int val) {
	while (i <= n) {
		tree[i] += val;
		i += (i & -i);
	}
}

int main()
{
	int tcase = 0;
	cin >> tcase;
	for (int i = 1; i <= tcase; i++) {
		cin >> n >> q;
		for (int j = 1; j <= n; j++) {
			cin >> arr[j];
			update(j, arr[j]);
		}
		cout << "Case " << i << ":\n";
		for (int j = 0; j < q; j++) {
			int a, b, c;
			cin >> a;
			if (a == 1) {
				cin >> b; b++;
				cout << arr[b] << "\n";
				update(b, -arr[b]);
				arr[b] = 0;
			}
			else if (a == 2) {
				cin >> b >> c; b++;
				update(b, c);
				arr[b] += c;
			}
			else {
				cin >> b >> c; b++, c++;
				cout << range_sum(b, c) << "\n";
			}
		}
	}

	return 0;
}
