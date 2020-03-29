/*
[BOJ] 16236. 아기 상어
아기 상어 주변에 물고기를 전부 bfs로 순회하고 순회한 값을 리스트로 저장한다.
리스트에서 규칙에 따라 가장 우선순위 높은 물고기를 먹는다. 그리고 전부 지운다음 다시 물고기를 찾는다.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, ans, eated, num = 1;
int dir[4][2] = {{-1, 0},{1, 0},{0, -1},{0, 1}};
int map[20][20];
int cntmap[20][20];
struct shark{
    int x,y,z,cnt;
    shark(int _x, int _y, int _z, int _cnt):x(_x), y(_y), z(_z), cnt(_cnt){};
    
};
shark babe(shark(0,0,0,0));

bool compare(shark a, shark b){     // 거리, 위 x 작은거, 왼쪽 y 작은거
        if(a.cnt != b.cnt){
            return a.cnt < b.cnt; //? true : false;
        } else {
            if(a.x != b.x){
                return a.x < b.x; //? true : false;
            } else {
                return a.y < b.y; //? true : false;
            }
        }
    }

void bfs(vector<shark> &eat){
    queue<shark> q;
    bool visited[20][20];
    memset(visited, 0, sizeof(visited));
    q.push(babe);
    visited[babe.x][babe.y] = true;
    while(!q.empty()){
        int x = q.front().x, y = q.front().y;
        int size = q.front().z, count = q.front().cnt;
        q.pop();
        for(int i=0;i<4;i++){
            int mx = x + dir[i][0], my = y + dir[i][1];
            if(mx < 0 || my < 0 || mx >= n || my >= n) continue;
            if(visited[mx][my]) continue;
            if(map[mx][my] > babe.z) continue;
            //cout<<mx<<","<<my<<"\n";
            visited[mx][my] = true;
            q.push(shark(mx, my, map[mx][my], count+1));
            if(map[mx][my] != 0 && map[mx][my] < babe.z){
                eat.push_back(shark(mx, my, map[mx][my], count+1));
            }
        }
    }

}

void solve(){
    while(1){
        vector<shark> eat;
        bfs(eat);
        //cout<<eat.size()<<":"<<eat.empty()<<"\n";
        if(eat.empty()) break;
        if(eat.size() > 1)
            sort(eat.begin(), eat.end(), compare);
        /*cout<<"eat size : "<<eat.size()<<"="<<babe.z<<"\n";
        cout<<babe.x<<", "<<babe.y<<"\n";
        for(int i=0;i<eat.size();i++){
            cout<<map[eat[0].x][eat[0].y]<<"="<<eat[i].x<<":"<<eat[i].y<<" <> "<<eat[i].cnt<<"\n";
        }*/
        ans += eat[0].cnt;
        eated++;
        //cout<<eat[0].x<<","<<eat[0].y<<":"<<ans<<","<<eat[0].cnt<<"\n";
        map[eat[0].x][eat[0].y] = 0;
        cntmap[eat[0].x][eat[0].y] = num++;
        babe.x = eat[0].x;
        babe.y = eat[0].y;
        if(eated%babe.z == 0 && eated/babe.z == 1) {    // 3 % 6 = 0, 3 / 6 = 2
            babe.z++;
            eated = 0;
        }
    }
}

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
            if(map[i][j] == 9){
                babe = shark(i,j,2,0);
                map[i][j] = 0;
            }
        }
    }
    solve();
    cout<<ans<<"\n";
    return 0;
}