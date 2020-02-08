#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
/* 백준 14502 : 연구소
: dfs 안에 bfs 문제
input
7 7
2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
output
27
*/
int n, m;
int a[8][8];
int acopy[8][8];
int ans;
int dx[4] = { 0 , 0 , -1, 1 };
int dy[4] = { 1, -1, 0 ,0 };
void find_wall() {
	// bfs
	int temp[8][8];
	queue <pair<int, int> > q; // 큐 선언
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp[i][j] = a[i][j];
		}
	} // 복사
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 2) {
				q.push(make_pair(i, j));
			}
		}
	}// 바이러스 위치를 다 넣어줌
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (temp[nx][ny] == 0) {
					temp[nx][ny] = 2;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	int number = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0) {
				number++;
			}
		}
	}
	ans = max(number, ans);
}
void make_wall(int cnt) {
	// dfs
	if (cnt == 3) {
		find_wall();
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) {
				a[i][j] = 1;
				make_wall(cnt + 1);
				a[i][j] = 0;
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> acopy[i][j]; // 입력 받음			
		}
	}
	/* 벽을 만들어야 한다. 벽의 개수는 총 3개
	벽의 좌표 (wx1, wx1) (wx2, wx2) (wx3, wx3)
	조건 : 서로 좌표의 위치가 다르고 한번 나온 조합은 나올 필요가 없다
	 즉, 조합 문제
	*/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (acopy[i][j] == 0) {
				for (int k = 0; k < n; k++) {
					for (int w = 0; w < m;w++) {
						a[k][w] = acopy[k][w]; // 연구소 상황 복사			
					}
				}
				a[i][j] = 1;
				make_wall(1);
				a[i][j] = 0;
			}
		}
	}
	cout << ans << "\n";
}