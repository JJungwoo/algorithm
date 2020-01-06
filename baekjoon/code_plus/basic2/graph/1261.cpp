/*
[BOJ] 1261. 알고스팟
일반적인 BFS로 접근하면 못푼다;; 숨바꼭질 4 문제 처럼 BFS 간의 이동에 우선순위를 주어서
더 최소 비용이 드는 경로를 찾아줘야 한다. 
++ 인터넷을 찾아보니 덱을 사용하는 방법과 배열에 가중치 값을 추가해주는 다익스트라 방식이 있었다.
최소 신장 트리도 비슷한 방식으로 가능 한가보다.
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n,m;
int check[101][101];
int map[101][101];
queue<pair<int, int> > q;

void bfs(){
    q.push(make_pair(1,1));
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        if(x == n-1 && y == m-1){
            cout<<check[x][y]<<"\n";
            return;
        }
        for(int i=0;i<4;i++){
            int mx = x+dir[i][0], my = y+dir[i][1];
            if(mx < 0 || my < 0 || mx >= n || my >= m) continue;
            if(check[mx][my] != -1) continue;
            q.push(make_pair(mx, my));
            if(map[mx][my] == 1)
                check[mx][my] = (check[x][y] == -1 ? 0 : check[x][y]) + 1;
            else
                check[mx][my] = (check[x][y] == -1 ? 0 : check[x][y]);
        }
    }
}

int main()
{
    cin>>m>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d", &map[i][j]);
        }
    }
    memset(check, -1, sizeof(check));
    bfs();
    return 0;
}