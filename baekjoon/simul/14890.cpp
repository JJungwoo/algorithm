/*
[boj] 14890. 경사로
지나갈 수 있는 길의 조건 (길: 모든 단일 행 또는 열)
단일 행 또는 열에 수가 같으면 OK

시뮬레이션 문제를 계속 풀면서 드는 생각은 구현 방법은 계속 하다보면 조금씩 표현 방법이랄까
노하우가 생기는데, 여기서 문제는 시뮬레이션에서 구현하라는 방법만 그대로 구현하면 거의 해결된다.
거기서 나뉘어지는건 시간인데, 보통은 정확하게 구현하기 쉽지 않아서 빠르게 해결하기 어렵다.
그래서 중요한 건... 디버깅 메시지를 잘찍어서 어디가 잘못 구현된건지 빠르게 찾는게 중요한 것 같다..
시뮬 문제는 진짜 시간 잡고 풀어야겠다. 빠르게 구현하는게 관건인것 같다..
*/

#include <iostream>
#include <cmath>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, l, ans;
int map[100][100][2];
void print() {
	cout << "print\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout<<map[i][j][1]<<" ";
		}
		cout << "\n";
	}
}
void solve()
{
	for (int i = 0; i < n; i++) {
		int seq = 0, start = map[i][0][0], L = 0;
		//cout << start << ":" << i << "\n";// << "," << j << "\n";
		for (int j = 0; j < n; j++) {
			//cout << start << ": i " << i << ", j " << j << ":"<<map[i][j][0]<<", seq "<<seq<< " L:"<<L<< "\n";
			if (map[i][j][0] == start) {
				seq++;
				if (L > 0) {	// 경사를 내려가는 중이다.
					L--;
					map[i][j][1] = 1;
				}
			}
			// 경사가 1이다 --> 올라간다 or 내려간다.
			else if (abs(map[i][j][0] - start) == 1) {
				if (map[i][j][0] < start) {	// 내려간다
					if (L > 0) {	// 다 안내려 오고 내려와서 안돼
						break;
					}
					//cout << "내려간다 꽉잡아! : " << L << "\n";
					start = map[i][j][0];
					map[i][j][1] = 1;
					L = l - 1;		// 현재 내려온 위치 제외
					seq++;
				}
				else if(L <= 0) {	// 올라간다
					bool possible = true;
					int tmp = map[i][j - 1][0];
					for (int z = 1; z <= l; z++) {
						if (j - z < 0) {
							possible = false;
							break;
						}
						if (map[i][j - z][1] == 1 || map[i][j - z][0] != tmp) {
							possible = false;
							break;
						}
					}
					if (!possible) break;
					start = map[i][j][0];
					seq++;
					//cout << "seq:" << seq << "," << start << "\n";
				}
			}
			else break;	// 경사가 2이상이다.
		}
		if (seq == n && L <= 0) {
			//cout << "i idx: "<<i << "\n";
			ans++;
		}
		//print();
	}

	//cout << ans <<" !\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j][1] = 0;
		}
	}

	for (int j = 0; j < n; j++) {
		int seq = 0, start = map[0][j][0], L = 0;
		//cout << start << ":" << j << "\n";// << "," << j << "\n";
		for (int i = 0; i < n; i++) {
			//cout << start << ": i " << i << ", j " << j << ":" << map[i][j][0] << ", seq: " << seq << " L:" << L << "\n";
			if (map[i][j][0] == start) {
				seq++;
				if (L > 0) {
					L--;
					map[i][j][1] = 1;
				}
			}
			else if (abs(map[i][j][0] - start) == 1) {
				if (map[i][j][0] < start) {
					if (L > 0) {
						break;
					}
					//cout << "내려간다 꽉잡아! : " << L << "\n";
					start = map[i][j][0];
					map[i][j][1] = 1;
					L = l - 1;
					seq++;
				}
				else {	// 올라간다
					bool possible = true;
					int tmp = map[i-1][j][0];
					for (int z = 1; z <= l; z++) {
						if (i - z < 0) {
							possible = false;
							break;
						}
						if (map[i - z][j][1] == 1 || map[i - z][j][0] != tmp) {
							possible = false;
							break;
						}
					}
					if (!possible) break;
					start = map[i][j][0];
					seq++;
					//cout << "seq:" << seq << "," << start << "\n";
				}
			}
			else break;	// 경사가 2이상이다.
		}
		if (seq == n && L <= 0) {
			//cout << "j idx: " << j << "\n";
			ans++;
		}
		//print();
	}
}
int main()
{
	io;
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j][0];
		}
	}
	solve();
	cout << ans << "\n";
	return 0;
}