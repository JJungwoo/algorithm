/*
[BOJ] 9007 카누 선수
*/
/*
#include <iostream>
using namespace std;
typedef long long ll;
int T, k, n;
int student[4][1001];

bool optimize(int mid) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < n; j++) {
			cin >> student[i][j];
		}
	}
}

void devision() {
	int lo = 0, hi = 1e7;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (optimize(mid))
			lo = mid;
		else
			hi = mid;
	}
}

int main()
{
	cin >> T;
	while (T--) {
		cin >> k >> n;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < n; j++) {
				cin >> student[i][j];
			}
		}
		devision();
		
	}
	return 0;
}
*/