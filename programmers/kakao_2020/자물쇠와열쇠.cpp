/*
자물쇠 = N x N
열쇠 = M x M
*/
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;
int n, m;
vector<vector<int> > tmp;

inline void turn_key(vector<vector<int> > src, vector<vector<int> > &des) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			des[j][n - i - 1] = src[i][j];
		}
	}
}
//inline void print_key(vector<vector<int> > tmp, int size) {
inline void print_key(int tmp[60][60], int size) {
	cout << "print_map\n";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << tmp[i][j] << " ";
		}
		cout << "\n";
	}
}

inline void print_vec(vector<vector<int> > tmp) {
	cout << "print_map\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << tmp[i][j] << " ";
		}
		cout << "\n";
	}
}

bool solution(vector<vector<int> > key, vector<vector<int> > lock) {
	bool answer = false;
	n = key[0].size(), m = lock[0].size();
	for (int loop = 0; loop < 4; loop++) {    // 시계방향 돌리기
		vector<vector<int>> tmp = key;
		turn_key(key, tmp);
		//print_vec(tmp);
		
		int size = n + (m - 1) * 2;
		cout << size << "," << n << "," << m << "\n";
		for (int i = 0; i < size - (n - 1); i++) {
			for (int j = 0; j < size - (n - 1); j++) {
				int map[60][60];
				//print_vec(tmp);
				memset(map, 0, sizeof(map));
 				//for (int x = i, kx = 0; x < i + n - 1; kx++, x++) {
				//	for (int y = j, ky = 0; y < i + n - 1; ky++, y++) {
				for (int x = i, kx = 0; kx < n; kx++, x++) {
					for (int y = j, ky = 0; ky < n; ky++, y++) {
						map[x][y] = tmp[kx][ky];
						//cout << tmp[kx][ky] << " ";
						//cout << x << "," << y << ":" << map[x][y] << "=" << tmp[kx][ky] << "\n";
					}
					cout << "\n";
				}
				//print_vec(key, n);
				//print_key(map, size);
				//print_vec(lock);
				int sum = 0;
				for (int x = n - 1, kx = 0; x < n - 1 + m; x++, kx++) {
					for (int y = n - 1, ky = 0; y < n - 1 + m; y++, ky++) {
						sum += (map[x][y] ^ lock[kx][ky]);
					}
				}
				//cout << sum << "\n";
				if (sum == m * m) {
					answer = true;
					return answer;
				}

			}
		}
		
		key = tmp;
	}

	return answer;
}

int main()
{
	vector<vector<int> > key, lock;
	key = { {0, 0, 0},{1, 0, 0},{0, 1, 1} };
	lock = { {1, 1, 1},{1, 1, 0},{1, 0, 1} };
	cout << solution(key, lock) << "\n";

	return 0;
}