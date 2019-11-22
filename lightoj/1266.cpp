/*
http://www.lightoj.com/volume_showproblem.php?problem=1266
Light OJ 1266 - Points in Rectangle
*/
#include <iostream>
using namespace std;

int tree[1005][1005];
int arr[1005][1005];
int n, q;

int sum(int x, int y) {
	int ret = 0;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
			ret += tree[i][j];
	return ret;
}

int range_sum(int x1, int y1, int x2, int y2) {
	return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
}

void add(int x, int y, int val) {
	for (int i = x; i <= 1001; i = i | (i + 1))
		for (int j = y; j <= 1001; j = j | (j + 1))
			tree[i][j] += val;
}

int main()
{
	cin >> n;
	for (int t = 1; t <= n; t++) {
		cin >> q;
		cout << "Case " << t << ":\n";
		for (int i = 0; i <= 1001; i++)
			for (int j = 0; j <= 1001; j++)
				tree[i][j] = arr[i][j] = 0;
		for (int i = 0; i < q; i++) {
			int a, b, c, d, e;
			cin >> a;
			if (a == 0) {
				cin >> b >> c; b++, c++;
				if (arr[b][c] == 1)
					continue;
				arr[b][c] = 1;
				add(b, c, 1);
			}
			else {
				cin >> b >> c >> d >> e; b++, c++, d++, e++;
				cout << range_sum(b, c, d, e) << "\n";
			}
		}
	}
	return 0;
}