
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/* 
    백준 1261 알고스팟
운영진이 미로에 갇힘.
미로 크기 n*m, 미로는 빈방 혹은 벽으로 이뤄짐
운영진은 여러명이지만 항상 같은 방에있음
상하좌우로 이동가능, 알고스팟 무기 AOJ 로 벽 부수기 가능
1,1, 에서 n, m 으로 이동
최소 몇개의 벽을 부서야 하는지.
-> bfs + 우선순위 큐 ( 시간이 더 걸림)
-> 다익스트라 알고리즘으로도 풀수있다고 함. ( 더 좋은 방법)
*/
#define INF 987654321
int n, m;
int dx[4] = { 0,1, 0, -1};
int dy[4] = {1,0,-1,0};
priority_queue <pair<int,pair<int,int> > > pq; // 3 개 변수를 가진 pair
int map[101][101];
int answer[101][101];
void bfs(){
    answer[1][1] = map[1][1];
    pq.push(make_pair(-answer[1][1],make_pair(1,1))); // 큐에 입력
    // -  가 붙는 이유 : 우선순위 큐라서 sorting 하기 위해서
     while(!pq.empty()){
         int cost = -pq.top().first;
         int x = pq.top().second.first;
         int y = pq.top().second.second;
         cout<<"x : y "<<x<<" : "<<y<<" = "<<cost<<"\n";
         pq.pop();
        for(int i = 0 ; i < 4; i++){
             int nx = x + dx[i];
             int ny = y + dy[i];
            if(nx <1 || nx >n || ny < 1 || ny > m) continue;  // 범위 초과하면 컨팅뉴
            int ncost =  cost + map[nx][ny];
            if(answer[nx][ny] > ncost){
                answer[nx][ny] = ncost;
                cout << "nx : ny = " << nx<<":"<< ny << " ncost : " << ncost<<"\n";
                pq.push(make_pair(-ncost, make_pair(nx,ny)));
            }
        }   
     }
}
int main(){
    scanf("%d %d", &n, &m);
    fill(&answer[0][0],&answer[101][101], INF); 
    for(int i = 1; i <=n; i++){
        for(int j = 1 ; j <= m ; j++){
            scanf("%1d", &map[i][j]);           
        }
        /*
        string str; cin >> str;
		for(int j = 1; j <= m; j++) 
            map[i][j] = str[j-1] - '0';
        */    
    }
    cout<<n<<","<<m<<"\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf(" i: %d j: %d = %d", i, j, map[i][j]);
        }
        printf("\n");
    }
    bfs();
    cout << answer[n][m]<<"\n";
}