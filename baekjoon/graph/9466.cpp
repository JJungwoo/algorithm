/*
[boj] 9466. 텀 프로젝트
시간초과.. 
방문 체크를 해줘야함.. 어렵다;
*/
#include <iostream>
#include <vector>
#include <cstring>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int t, n, ans;
int student[100001];
bool visited[100001], done[100001];
void cycle(int idx) {
	visited[idx] = true;
	int next = student[idx];
	//cout << idx << ":" << next << "\n";
	if (!visited[next]) {
		cycle(next);
	}
	else {
		if (!done[next]) {
			for (int i = next; i != idx; i = student[i]) {
				//cout << i << "\n";
				ans++;
			}
			ans++;
		}
	}
	done[idx] = true;
}
int main()
{
	io;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> student[i];
		}
		memset(visited, 0, sizeof(visited));
		memset(done, 0, sizeof(done));
		ans = 0;
		for (int i = 1; i <= n; i++) {
			if (visited[i]) continue;
			cycle(i);
		}		
		cout << n - ans << "\n";
	}
	return 0;
}