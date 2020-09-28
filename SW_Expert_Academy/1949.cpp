/*
[SWEA] 1949. [모의 SW 역량테스트] 등산로 조성
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PoOKKAPIDFAUq
*/

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int map[9][9], tmp[9][9], max_value;
vector<pair<int, int> > v;
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
struct obj {
    int x, y, depth;
    obj(int _x, int _y, int _depth) : x(_x), y(_y), depth(_depth) {}
};

int bfs(int x, int y, int n) {
    int max_depth = 0;
    queue<obj> q;
    q.push(obj(x,y,1));
    while(!q.empty()) {
        obj cur = q.front();
        q.pop();
        if(cur.depth > max_depth) {
            max_depth = cur.depth;
        }
        for(int i=0;i<4;i++) {
            int mx = cur.x + dir[i][0], my = cur.y + dir[i][1];
            if(mx < 0 || my < 0 || mx >= n || my >= n) continue;
            if(tmp[mx][my] >= tmp[cur.x][cur.y]) continue;
            q.push(obj(mx,my,cur.depth+1));
        }
    }

    return max_depth;
}
int solve(int x, int y, int k, int n) {
    int ret = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            tmp[i][j] = map[i][j];

    for(int i=0;i<=k;i++) {
        tmp[x][y] -= i;
        for(auto it : v) {
            ret = max(ret, bfs(it.first, it.second, n));
        }
        tmp[x][y] += i;
    }

    return ret;
}
int main() 
{
    io;
    int test_case;
    int T, N, K;
    cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        max_value = 0;
        v.clear();
        int answer = 0;
        cin >> N >> K;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                cin >> map[i][j];
                max_value = max(map[i][j], max_value);
            }
        }

        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                if(map[i][j] == max_value)
                    v.push_back(make_pair(i, j));

        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                answer = max(answer, solve(i, j, K, N));
            }
        }
        cout<<"#"<<test_case<<" "<<answer<<"\n";
    }
    return 0;
}

