/*
[boj] 5373. 큐빙
위 흰, 아래 노랑, 앞 빨간, 뒷 오렌지, 왼 초록, 오른 파랑
흰 w, 노 y, 빨 r, 오 o, 초 g, 파 b

위(흰), 뒤(아래,노랑), 상(뒷, 오렌지), 우(오른, 파랑), 하(앞, 빨간), 좌(왼, 초록)
0(흰), 1(노랑), 2(오렌지, 상), 3(파랑, 우), 4(빨간, 하), 5(초록, 좌)
*/

#include <iostream>
#include <cmath>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
char block[6] = { 'w','y','o','b','r','g' };
// 윗면을 기준으로 위(흰), 뒤(아래,노랑), 상(뒷, 오렌지), 우(오른, 파랑), 하(앞, 빨간), 좌(왼, 초록)
int cube[6][3][3];	
int tcase, n;
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} }; // 상 우 하 좌
char map[3][3];
void init() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int z = 0; z < 6; z++) {
				cube[z][i][j] = z;
			}
			map[i][j] = 'w';
		}
	}
}
void detailprintCube() {
	for (int z = 0; z < 6; z++) {
		cout << z << "\n";
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				//cout << block[cube[0][i][j]];
				cout << cube[z][i][j];
			}
			cout << "\n";
		}
	}
}
void printCube() {
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << block[cube[0][i][j]];
		}
		cout << "\n";
	}
	
}
int main()
{
	io;
	cin >> tcase;
	while (tcase--) {
		init();
		cin >> n;
		for (int i = 0; i < n; i++) {
			char cmd[2];
			cin >> cmd[0] >> cmd[1];
			switch(cmd[0]) {
			case 'U':	// 윗, 윗면은 그대로 상우하좌(2,3,4,5)의 인접 3면만 움직임
				if (cmd[1] == '+') {	// 시계방향
					swap(cube[2][0][0], cube[5][0][0]);
					swap(cube[2][0][1], cube[5][0][1]);
					swap(cube[2][0][2], cube[5][0][2]);

					swap(cube[5][0][0], cube[4][0][0]);
					swap(cube[5][0][1], cube[4][0][1]);
					swap(cube[5][0][2], cube[4][0][2]);

					swap(cube[4][0][0], cube[3][0][0]);
					swap(cube[4][0][1], cube[3][1][0]);
					swap(cube[4][0][2], cube[3][2][0]);

				}
				else {	// 반시계방향
					swap(cube[2][0][0], cube[3][0][0]);
					swap(cube[2][0][1], cube[3][0][1]);
					swap(cube[2][0][2], cube[3][0][2]);

					swap(cube[3][0][0], cube[4][0][0]);
					swap(cube[3][0][1], cube[4][0][1]);
					swap(cube[3][0][2], cube[4][0][2]);

					swap(cube[4][0][0], cube[5][0][0]);
					swap(cube[4][0][1], cube[5][1][0]);
					swap(cube[4][0][2], cube[5][2][0]);
				}
				break;
			case 'F':	// 앞	앞 기준, 위0, 왼4, 밑1, 오5
				if (cmd[1] == '+') {	// 시계방향
					swap(cube[1][2][0], cube[5][0][0]);
					swap(cube[1][2][1], cube[5][1][0]);
					swap(cube[1][2][2], cube[5][2][0]);

					swap(cube[3][0][0], cube[1][2][0]);
					swap(cube[3][1][0], cube[1][2][1]);
					swap(cube[3][2][0], cube[1][2][2]);

					swap(cube[0][2][0], cube[3][0][0]);
					swap(cube[0][2][1], cube[3][1][0]);
					swap(cube[0][2][2], cube[3][2][0]);

				}
				else {	// 반시계방향
					swap(cube[0][2][0], cube[3][0][0]);
					swap(cube[0][2][1], cube[3][1][0]);
					swap(cube[0][2][2], cube[3][2][0]);

					swap(cube[3][0][0], cube[1][2][0]);
					swap(cube[3][1][0], cube[1][2][1]);
					swap(cube[3][2][0], cube[1][2][2]);
				
					swap(cube[1][2][0], cube[5][0][0]);
					swap(cube[1][2][1], cube[5][1][0]);
					swap(cube[1][2][2], cube[5][2][0]);
				}
				break;
			case 'B':	// 뒷
				if (cmd[1] == '+') {	// 시계방향
					swap(cube[0][2][0], cube[3][0][2]);
					swap(cube[0][2][1], cube[3][1][2]);
					swap(cube[0][2][2], cube[3][2][2]);

					swap(cube[3][0][2], cube[1][0][0]);
					swap(cube[3][1][2], cube[1][0][1]);
					swap(cube[3][2][2], cube[1][0][2]);

					swap(cube[1][0][0], cube[5][0][0]);
					swap(cube[1][0][1], cube[5][1][0]);
					swap(cube[1][0][2], cube[5][2][0]);
				}
				else {	// 반시계방향
					swap(cube[1][2][0], cube[5][0][0]);
					swap(cube[1][2][1], cube[5][1][0]);
					swap(cube[1][2][2], cube[5][2][0]);

					swap(cube[3][0][0], cube[1][0][0]);
					swap(cube[3][1][0], cube[1][0][1]);
					swap(cube[3][2][0], cube[1][0][2]);

					swap(cube[0][2][0], cube[3][0][0]);
					swap(cube[0][2][1], cube[3][1][0]);
					swap(cube[0][2][2], cube[3][2][0]);
				}
				break;
			case 'L':	// 왼
				if (cmd[1] == '+') {	// 시계방향
					swap(cube[1][2][0], cube[5][0][0]);
					swap(cube[1][2][1], cube[5][1][0]);
					swap(cube[1][2][2], cube[5][2][0]);

					swap(cube[3][0][0], cube[1][2][0]);
					swap(cube[3][1][0], cube[1][2][1]);
					swap(cube[3][2][0], cube[1][2][2]);

					swap(cube[0][2][0], cube[3][0][0]);
					swap(cube[0][2][1], cube[3][1][0]);
					swap(cube[0][2][2], cube[3][2][0]);

				}
				else {	// 반시계방향
					swap(cube[0][2][0], cube[3][0][0]);
					swap(cube[0][2][1], cube[3][1][0]);
					swap(cube[0][2][2], cube[3][2][0]);

					swap(cube[3][0][0], cube[1][2][0]);
					swap(cube[3][1][0], cube[1][2][1]);
					swap(cube[3][2][0], cube[1][2][2]);

					swap(cube[1][2][0], cube[5][0][0]);
					swap(cube[1][2][1], cube[5][1][0]);
					swap(cube[1][2][2], cube[5][2][0]);
				}
				break;
			case 'R':	// 오
				if (cmd[1] == '+') {	// 시계방향
					swap(cube[1][2][0], cube[5][0][0]);
					swap(cube[1][2][1], cube[5][1][0]);
					swap(cube[1][2][2], cube[5][2][0]);

					swap(cube[3][0][0], cube[1][2][0]);
					swap(cube[3][1][0], cube[1][2][1]);
					swap(cube[3][2][0], cube[1][2][2]);

					swap(cube[0][2][0], cube[3][0][0]);
					swap(cube[0][2][1], cube[3][1][0]);
					swap(cube[0][2][2], cube[3][2][0]);

				}
				else {	// 반시계방향
					swap(cube[0][2][0], cube[3][0][0]);
					swap(cube[0][2][1], cube[3][1][0]);
					swap(cube[0][2][2], cube[3][2][0]);

					swap(cube[3][0][0], cube[1][2][0]);
					swap(cube[3][1][0], cube[1][2][1]);
					swap(cube[3][2][0], cube[1][2][2]);

					swap(cube[1][2][0], cube[5][0][0]);
					swap(cube[1][2][1], cube[5][1][0]);
					swap(cube[1][2][2], cube[5][2][0]);
				}
				break;
			}
		}
		printCube();
		//detailprintCube();
	}
	return 0;
}