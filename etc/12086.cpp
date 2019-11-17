/*

*/
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct fenwicktree {
	vector<int> bit;
	int n;

	fenwicktree(int n) {
		this->n = n + 1;
		bit.assign(n + 1, 0);
	}
	fenwicktree(vector<int> a)
		: fenwicktree(a.size()) {
		for (size_t i = 0; i < a.size(); i++)
			add(i, a[i]);
	}

	int sum(int idx) {
		int ret = 0;
		for (++idx; idx > 0; idx -= idx & -idx)
			ret += bit[idx];
		return ret;
	}

	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}

	void add(int idx, int delta) {
		for (++idx; idx < n; idx += idx&-idx)
			bit[idx] += delta;
	}
};




int main()
{
	int n, input, x, y, tcase = 1;
	int t = 4&-2;
	printf("%d\n", t);
	while (1) {
		vector<int> arr;
		arr.push_back(0);
		cin >> n;
		if (n == 0)
			break;
		for (int i = 1; i <= n; i++) {
			cin >> input;
			arr.push_back(input);
		}
		fenwicktree fw = fenwicktree(arr);
		while (1) {
			string ctype;
			cin >> ctype;
			cout << "Case "<< tcase << ":\n";
			if (ctype == "M") {
				cin >> x >> y;
				cout<< fw.sum(x, y) << "\n";
			}
			else if (ctype == "S") {
				cin >> x >> y;
				fw.add(x, y);
			}
			else {
				break;
			}
		}
		tcase++;
		
	}
	
	return 0;
}
	*/