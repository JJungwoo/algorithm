/*
[boj] 2933. 미네랄
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int r, c, n, turn, clusterCnt;
char map[100][100];
int del[100];
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
bool passCluster[101];
int visited[100][100];
struct pos {
	int x, y;
};

bool compare(pos a, pos b) {
	return a.x > b.x;
}
void bfs(int x, int y, vector<pos> cluster[101]) {
	queue<pos> q;
	q.push({ x,y });
	visited[x][y] = clusterCnt;
	cluster[clusterCnt].push_back(q.front());
	while (!q.empty()) {
		int dx = q.front().x, dy = q.front().y;
		q.pop();
		cluster[clusterCnt].push_back({ dx, dy });
		if (dx == r - 1) {
			passCluster[clusterCnt] = true;
		}
		for (int i = 0; i < 4; i++) {
			int mx = dx + dir[i][0], my = dy + dir[i][1];
			if (mx < 0 || my < 0 || mx >= r || my >= c) continue;
			if (map[mx][my] != 'x') continue;
			if (visited[mx][my] != -1)continue;
			visited[mx][my] = clusterCnt;
			//cluster[clusterCnt].push_back({ mx, my });
			q.push({ mx,my });
		}
	}
}
void print() {
	cout << "print\n";
	for (int x = 0; x < r; x++) {
		for (int y = 0; y < c; y++) {
			cout << visited[x][y] <<"   ";
		}
		cout << "\n";
	}
}
void solve()
{
	for (int i = 0; i < n; i++) {
		vector<pos> cluster[101];
		int idx = (r - 1) - del[i];
		if (!turn){	// 왼
			for (int j = 0; j < c; j++) {
				if (map[idx][j] == 'x') {
					map[idx][j] = '.';
					break;
				}
			}
		}
		else {
			for (int j = c - 1; j >= 0; j--) {
				if (map[idx][j] == 'x') {
					map[idx][j] = '.';
					break;
				}
			}
		}
		
		// cluster check bfs
		memset(visited, -1, sizeof(visited));
		memset(passCluster, 0, sizeof(passCluster));
		for (int x = 0; x < r; x++) {
			for (int y = 0; y < c; y++) {
				if (map[x][y] == 'x' && visited[x][y] == -1) {
					bfs(x, y, cluster);
					clusterCnt++;
				}
			}
		}
		//print();
		for (int c = 0; c < clusterCnt; c++) {
			//cout << c << " is pass! : " << passCluster[c] << "\n";
			if (passCluster[c]) {
				continue;
			}
			sort(cluster[c].begin(), cluster[c].end(), compare);
			int csize = cluster[c].size();
			//cout << csize << "\n";
			bool check = false;
			while (csize > 0) {
				//cout << "cluster : \n";
				for (int loop = 0; loop < csize; loop++) {
					int mx = cluster[c][loop].x + dir[1][0], my = cluster[c][loop].y + dir[1][1];
					//cout << mx << "," << my << "\n";
					if (mx >= r || (map[mx][my] == 'x' && visited[mx][my] != c)) {
						//cout << mx << "," << my << "\n";
						check = true;
						break;
					}
				}
				if (check) break;
				else {		// 내려주기
					for (int loop = 0; loop < csize; loop++) {
						int mx = cluster[c][loop].x + dir[1][0], my = cluster[c][loop].y + dir[1][1];
						map[mx][my] = 'x';
						map[cluster[c][loop].x][cluster[c][loop].y] = '.';
						visited[mx][my] = c;
						visited[cluster[c][loop].x][cluster[c][loop].y] = -1;
						cluster[c][loop].x = mx, cluster[c][loop].y = my;
					}
				}
			}
		}
		turn = (turn + 1) % 2;
		clusterCnt = 0;
	}
}
int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> del[i];
		del[i]--;
	}
	solve();
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
	return 0;
}
