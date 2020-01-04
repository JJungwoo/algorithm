/*
[BOJ] 7562. 나이트의 이동
처음 바로 BFS로 방향을 잡고 푸는데, 실수가 몇개 있었다.
먼저 한번 방문한 위치에 대해 체크하고 접근을 더이상 하지 않는 예외처리가 빠졌고
다음으로 map에 방문한 횟수 값을 담는데 테스트 케이스 마다 초기화를 안해줬었다.
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int t,n;
int map[301][301];
int dir[8][2] = \
{{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, \
{2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
pair<int, int> src, des;

void bfs()
{
    queue<pair<int, int> > q;
    q.push(make_pair(src.first, src.second));
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        if(x == des.first && y == des.second) {
            cout<<map[x][y]<<"\n";
            //cout<<x<<"->"<<mx<<","<<y<<"->"<<my<<","<<ans<<"\n";
            return;
        }
        for(int i=0;i<8;i++){
            int mx = x + dir[i][0], my = y + dir[i][1];
            if(mx < 0 || mx >= n || my < 0 || my >= n) continue;
            if(map[mx][my]) continue;
            map[mx][my] = map[x][y] + 1;
            q.push(make_pair(mx, my));
        }
    }
}

int main()
{
    io;
    cin>>t;
    while(t--){
        cin>>n;
        cin>>src.first>>src.second;
        cin>>des.first>>des.second;
        if(src.first == des.first && 
        src.second == des.second) {
            cout<<"0\n";
            continue;
        }
        bfs();
        memset(map, 0, sizeof(map));
    }

    return 0;
}