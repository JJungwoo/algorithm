/*
BOJ 
*/

/*
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
int n, cnt;
ll arr[1500][1500];

int main()
{
	ll max_value = 0;
	int idx;
	cin >> n;
	cnt = n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		max_value = max(max_value, arr[n - 1][i]);
		idx = i;
	}

	int tidx = n - 2;
	while (cnt--) {
		int max_i = 0;
		for (int i = 0; i < n; i++) {
			max_value = max(max_value, arr[n - 1][i]);
			max_i = i;
		}
		if (arr[tidx][idx] > max_value) {
			tidx--;
		}
		else {
			idx = max_i;

		}
			
	}
	
	

	return 0;
}
*/