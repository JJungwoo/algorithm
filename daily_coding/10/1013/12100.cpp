/*
[boj] 12100. 2048
https://www.acmicpc.net/problem/12100
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int dir[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // 위에서부터 시계 방향
int N, answer;
int map[21][21], copymap[21][21];
vector<int> dirs;
inline void swap(int *A, int *B) {
    int tmp = *A;
    *A = *B;
    *B = tmp;
}
void copy_map() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            copymap[i][j] = map[i][j];
        }
    }
}
int max_find_map() {
    int ret = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            ret = max(ret, copymap[i][j]);
        }
    }
    return ret;
}
inline void move_block(int x, int y, int d, bool change[21][21]) {
	while (1) {
		int mx = x + dir[d][0], my = y + dir[d][1];
		if (mx < 0 || my < 0 || mx >= N || my >= N) break;
		if (copymap[mx][my] != 0) {
			if (!change[mx][my] && copymap[mx][my] == copymap[x][y]) {
				copymap[mx][my] += copymap[x][y];
				copymap[x][y] = 0;
				change[mx][my] = true;
				break;
			}
			else break;
		}
		else {
			copymap[mx][my] = copymap[x][y];
			copymap[x][y] = 0;
		}
		x = mx, y = my;
	}
}
void move_map(int d) {
    bool visited[21][21];   // 이동 후 합쳐진거 체크 배열
    memset(visited, false, sizeof(visited));
    switch(d) {
        case 0: // 위
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(copymap[i][j] != 0)
                    move_block(i, j, d, visited);
            }
        }
        break;
        case 1: // 오른
        for(int j=N-1;j>=0;j--) {
            for(int i=0;i<N;i++) {
                if(copymap[i][j] != 0)
                    move_block(i, j, d, visited);
            }
        }
        break;
        case 2: // 아래
        for(int i=N-1;i>=0;i--) {
            for(int j=0;j<N;j++) {
                if(copymap[i][j] != 0)
                    move_block(i, j, d, visited);
            }
        }
        break;
        case 3: // 왼
        for(int j=0;j<N;j++) {
            for(int i=0;i<N;i++) {
                if(copymap[i][j] != 0)
                    move_block(i, j, d, visited);
            }
        }
        break;
    }
}
int simul() {
    int ret = -1;
    int tmp_map[21][21];
    copy_map();
    for(int i=0;i<dirs.size();i++) {
        move_map(dirs[i]);
    }
    ret = max_find_map();
    return ret;
}
void solve(int cnt) {
    if(cnt == 5) {
        answer = max(answer, simul());
        return ;
    }
    for(int i=0;i<4;i++) {
        dirs.push_back(i);
        solve(cnt + 1);
        dirs.pop_back();
    }
}
int main() 
{
    io;
    cin >> N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> map[i][j];
        }
    }
    solve(0);
    cout << answer << "\n";
    return 0;
}