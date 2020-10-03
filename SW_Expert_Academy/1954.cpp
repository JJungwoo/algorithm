/*
[SWEA] 1953. [모의 SW 역량테스트] 탈주범 검거
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpLlKAQ4DFAUq
*/

#include <iostream>
#include <cstring>
#include <queue>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int field[52][52];
bool visited[52][52];
int bfs(int n, int m, int r, int c, int l) {
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(r, c), l - 1));
    visited[r][c] = true;
    while(!q.empty()) {
        int x = q.front().first.first, y = q.front().first.second;
        int time = q.front().second;
        q.pop();
        if(time == 0)
            break;
        
        switch(field[x][y]) {
            case 1:
            if (!visited[x + 1][y] && (field[x + 1][y] == 1 || field[x + 1][y] == 2 || field[x + 1][y] == 4 || field[x + 1][y] == 7)) {
                visited[x + 1][y] = true;
                q.push(make_pair(make_pair(x + 1, y), time-1));
            }
            if (!visited[x - 1][y] && (field[x - 1][y] == 1 || field[x - 1][y] == 2 || field[x - 1][y] == 5 || field[x - 1][y] == 6)) {
                visited[x - 1][y] = true;
                q.push(make_pair(make_pair(x - 1, y), time-1));
            }
		    if (!visited[x][y + 1] && (field[x][y + 1] == 1 || field[x][y + 1] == 3 || field[x][y + 1] == 6 || field[x][y + 1] == 7)) {
                visited[x][y + 1] = true;
                q.push(make_pair(make_pair(x, y + 1) , time-1));
            }
		    if (!visited[x][y - 1] && (field[x][y - 1] == 1 || field[x][y - 1] == 3 || field[x][y - 1] == 4 || field[x][y - 1] == 5)) {
                visited[x][y - 1] = true;
                q.push(make_pair(make_pair(x, y - 1), time-1));
            }
            break;
            case 2:
            if (!visited[x + 1][y] && (field[x + 1][y] == 1 || field[x + 1][y] == 2 || field[x + 1][y] == 4 || field[x + 1][y] == 7)) {
                visited[x + 1][y] = true;
                q.push(make_pair(make_pair(x + 1, y), time-1));
            }
            if (!visited[x - 1][y] && (field[x - 1][y] == 1 || field[x - 1][y] == 2 || field[x - 1][y] == 5 || field[x - 1][y] == 6)) {
                visited[x - 1][y] = true;
                q.push(make_pair(make_pair(x - 1, y), time-1));
            }
            break;
            case 3:
            if (!visited[x][y + 1] && (field[x][y + 1] == 1 || field[x][y + 1] == 3 || field[x][y + 1] == 6 || field[x][y + 1] == 7)) {
                visited[x][y + 1] = true;
                q.push(make_pair(make_pair(x, y + 1), time-1));
            }
            if (!visited[x][y - 1] && (field[x][y - 1] == 1 || field[x][y - 1] == 3 || field[x][y - 1] == 4 || field[x][y - 1] == 5)) {
                visited[x][y - 1] = true;
                q.push(make_pair(make_pair(x, y - 1), time-1));
            }
            break;
            case 4:
            if (!visited[x - 1][y] && (field[x - 1][y] == 1 || field[x - 1][y] == 2 || field[x - 1][y] == 5 || field[x - 1][y] == 6)) {
                visited[x - 1][y] = true;
                q.push(make_pair(make_pair(x - 1, y), time-1));
            }
            if (!visited[x][y + 1] && (field[x][y + 1] == 1 || field[x][y + 1] == 3 || field[x][y + 1] == 6 || field[x][y + 1] == 7)) {
                visited[x][y + 1] = true;
                q.push(make_pair(make_pair(x, y + 1), time-1));
            }
            break;
            case 5:
            if (!visited[x + 1][y] && (field[x + 1][y] == 1 || field[x + 1][y] == 2 || field[x + 1][y] == 4 || field[x + 1][y] == 7)) {
                visited[x + 1][y] = true;
                q.push(make_pair(make_pair(x + 1, y), time-1));
            }
            if (!visited[x][y + 1] && (field[x][y + 1] == 1 || field[x][y + 1] == 3 || field[x][y + 1] == 6 || field[x][y + 1] == 7)) {
                visited[x][y + 1] = true;
                q.push(make_pair(make_pair(x, y + 1), time-1));
            }
            break;
            case 6:
            if (!visited[x + 1][y] && (field[x + 1][y] == 1 || field[x + 1][y] == 2 || field[x + 1][y] == 4 || field[x + 1][y] == 7)) {
                visited[x + 1][y] = true;
                q.push(make_pair(make_pair(x + 1, y), time-1));
            }
            if (!visited[x][y - 1] && (field[x][y - 1] == 1 || field[x][y - 1] == 3 || field[x][y - 1] == 4 || field[x][y - 1] == 5)) {
                visited[x][y - 1] = true;
                q.push(make_pair(make_pair(x, y - 1), time-1));
            }
            break;
            case 7:
            if (!visited[x - 1][y] && (field[x - 1][y] == 1 || field[x - 1][y] == 2 || field[x - 1][y] == 5 || field[x - 1][y] == 6)) {
                visited[x - 1][y] = true;
                q.push(make_pair(make_pair(x - 1, y), time-1));
            }
            if (!visited[x][y - 1] && (field[x][y - 1] == 1 || field[x][y - 1] == 3 || field[x][y - 1] == 4 || field[x][y - 1] == 5)) {
                visited[x][y - 1] = true;
                q.push(make_pair(make_pair(x, y - 1), time-1));
            }
            break;
        }
    }
    int cnt = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(visited[i][j])
                cnt++;
        }
    }
    return cnt;
}
int main() 
{
    io;
    int test_case;
    int T, N, M, R, C, L;
    cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int answer = 0;
        memset(field, 0, sizeof(field));
        memset(visited, 0, sizeof(visited));
        cin >> N >> M >> R >> C >> L; 
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=M;j++) {
                cin >> field[i][j];
            }
        }

        answer = bfs(N, M, R+1, C+1, L);
        cout<<"#"<<test_case<<" "<<answer<<"\n";
    }
    return 0;
}