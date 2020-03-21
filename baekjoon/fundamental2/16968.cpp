/*
[boj] 16968. 차량 번호판 1
*/

#include <iostream>
#include <string>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

#define D 10
#define C 26
string ncar;
int ncsize, ans;

void solve(int cnt, int check) {
	if (cnt == ncsize) {
		ans++;
		return;
	}

	int tmp = ncar[cnt] == 'd' ? D : C;
	if (cnt == 0) {
		for (int i = 0; i < tmp; i++) {
			solve(cnt + 1, i);
		}
	}
	else {
		if (ncar[cnt - 1] == ncar[cnt]) {
			for (int i = 0; i < tmp; i++) {
				if (i == check) continue;
				solve(cnt + 1, i);
			}
		}
		else {
			for (int i = 0; i < tmp; i++) {
				solve(cnt + 1, i);
			}
		}
	}
}

int main()
{
	io;
	cin >> ncar;
	ncsize = ncar.size();
	solve(0, 0);
	cout << ans << "\n";
	return 0;
}
