/*
[BOJ] 1261. 알고스팟
일반적인 BFS로 접근하면 못푼다;; 숨바꼭질 4 문제 처럼 BFS 간의 이동에 우선순위를 주어서
더 최소 비용이 드는 경로를 찾아줘야 한다. 
++ 인터넷을 찾아보니 덱을 사용하는 방법과 배열에 가중치 값을 추가해주는 다익스트라 방식이 있었다.
최소 신장 트리도 비슷한 방식으로 가능 한가보다.
ref: https://rebas.kr/657
https://deliorange.tistory.com/97
*/
#include <iostream>
#include <queue>
using namespace std;

struct maze{
    int x,y,d;
    maze(){}
    maze(int _x, int _y, int _d) : x(_x), y(_y), d(_d) {}
    bool operator < (const maze t) const { return d > t.d; }
};

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int INF = 1e9;
int n,m;
int dist[101][101];
int map[101][101];
priority_queue<maze> pq;

void dijkstra(){
    pq.push(maze(1,1,0));
    dist[1][1] = 0;
    while(!pq.empty()){
        int x = pq.top().x, y = pq.top().y, d = pq.top().d;
        pq.pop();
        for(int i=0;i<4;i++){
            int mx = x + dir[i][0], my = y + dir[i][1];
            int md = d + map[mx][my];
            if(mx < 1 || my < 1 || mx > n || my > m) continue;
            if(dist[mx][my] > md){
                dist[mx][my] = md;
                pq.push(maze(mx, my, md));
            }
        }
    }
}

int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%1d", &map[i][j]);
            dist[i][j] = INF;
        }
    }
    dijkstra();
    cout<<dist[n][m]<<"\n";
    return 0;
}