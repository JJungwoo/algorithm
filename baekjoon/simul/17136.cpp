/*
[boj] 17136. 색종이 붙이기
전역 배열로 풀이 방법: https://hororolol.tistory.com/82
함수에 배열 인자값 넘기는 방법: https://regularmember.tistory.com/102
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define cpMax 10

int map[10][10];

int main()
{
    io;
    for(int i=0;i<cpMax;i++){
        for(int j=0;j<cpMax;j++){
            cin>>map[i][j];
        }
    }

    return 0;
}

/*
int ans = 987654321;
int map[11][11];
int cpaper[5];
vector<pair<int, int> > vp;
vector<pair<int, int> > remove_vp;
void recovery_paper() {
	for (int i = 0; i < remove_vp.size(); i++) {
		if (map[remove_vp[i].first][remove_vp[i].second] == 0)
			map[remove_vp[i].first][remove_vp[i].second] == 1;
	}
}
void copy_map(int tmp_map[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			tmp_map[i][j] = map[i][j];
		}
	}
}
bool check_paper(int value, int x, int y)
{
	for()
	return true;
}
bool map_check(int tmp_map[10][10])
{
	for (int i = 0; i < cpMax; i++) {
		for (int j = 0; j < cpMax; j++) {
			if (tmp_map[i][j]) {
				return true;
			}
		}
	}
	return false;
}
bool solve(bool exit, int tmp_map[10][10])
{
	if (exit) {
		int total = 0;
		for (int i = 0; i < 5; i++)
			total += (5 - cpaper[i]);
		if (ans > total) ans = total;
		return;
	}
	for (int z = 0; z < vp.size(); z++) {
		if (map[vp[z].first][vp[z].second] == 0) continue;
		for (int i = 0; i < 5; i++) {
			if (cpaper[i]) {
				if (check_paper(i, vp[z].first, vp[z].second)) {
					cpaper[i]--;
					int tmp_map[10][10];
					copy_map(tmp_map);
					solve(!map_check(tmp_map));
					recovery_paper();
					cpaper[i]++;
				}
			}
		}
	}
}
int main()
{
	io;
	for (int i = 0; i < 5; i++)
		cpaper[i] = 5;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
			if (map[i][j]) {
				vp.push_back(make_pair(i, j));
			}
		}
	}
	solve(false);
	cout << ans << "\n";
	return 0;
}
*/