/*
[boj] 16946. 벽 부수고 이동하기 4 
https://www.acmicpc.net/problem/16946
*/

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, m;
int map[1001][1001], tmp[1001][1001];
vector<int> vfield;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
struct obj {
    int x, y;
    obj(int _x, int _y) : x(_x), y(_y) {};
};
int bfs(int x, int y, int cnt) {
    int result = 1;
    queue<obj> q;
    q.push(obj(x,y));
    tmp[x][y] = cnt;
    while(!q.empty()) {
        struct obj cur = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int mx = cur.x + dir[i][0], my = cur.y + dir[i][1];
            if(mx < 0 || my < 0 || mx >= n || my >= m) continue;
            if(tmp[mx][my] != 0 || map[mx][my] == 1) continue;
            tmp[mx][my] = cnt;
            q.push(obj(mx, my));
            result++;
        }
    }
    
    return result;
}
int main() 
{
    io;
    int space_cnt = 1;
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d", &map[i][j]);
        }
    }

    vfield.push_back(0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(tmp[i][j] == 0 && map[i][j] == 0) {
                vfield.push_back(bfs(i, j, space_cnt));
                space_cnt++;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j] == 0) printf("0");
            else {
                unordered_set<int> s; 
                int sum = 1;
                for(int d=0;d<4;d++){
                    int mx = i + dir[d][0], my = j + dir[d][1];
                    if(mx < 0 || my < 0 || mx >= n || my >= m) continue;
                    if(map[mx][my] == 1) continue;
                    if(s.find(tmp[mx][my]) != s.end()) continue;
                    s.insert(tmp[mx][my]);
                    sum += vfield[tmp[mx][my]];
                }
                printf("%d", sum%10);
            }
        }
        printf("\n");
    }

    return 0;
}

