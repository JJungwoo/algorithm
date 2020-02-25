/*
[BOJ] 16236. 아기상어
크기가 같은 물고기는 먹을 수 없지만 지나다닐수는 있다.
먹을 수 있는 물고기가 여러마리 일 때, 가장 가까운 물고기중 위에 물고기를 먼저 먹는다. 
이때, 위에 물고기도 여러마리면 왼쪽부터 먹는다.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, ans;
int map[20][20];
int dir[4][2] = {{0,-1},{-1,0},{1, 0},{0,1}};

struct shark{
    int x, y, level;
};
shark bshark;

bool check_map(){
    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res += map[i][j];
        }
    }
    if(res == 9) return true;
    else return false;
}
/*
void dfs(int x, int y, int level, int way, int cnt){
    if(check_map() == true) {
        return ;
    }

    for(int i=0;i<4;i++){
        x += dir[i][0], y += dir[i][1];
        if(x < 0 || y < 0 || x >= n || y >= n) continue;
    }
}
*/
bool cmp(const pair<int, pair<int, int> > &a, const pair<int , pair<int, int> > &b)
{
    if(a.first == b.first)
        return a.second.second < b.second.second;
}

void bfs(){
    queue<pair<pair<int, int>, pair<int, int> > > qp;
    qp.push(make_pair(make_pair(bshark.x, bshark.y),make_pair(bshark.level, 0)));
    while(!qp.empty()){
        int x = qp.front().first.first, y = qp.front().first.second;
        int level = qp.front().second.first, way = qp.front().second.second;
        qp.pop();
        if(check_map() == true){
            cout<<way<<"\n";
            return ;
        }
        int dp[20][20] = {0,};
        queue<pair<pair<int, int>, pair<int, int> > > inq;
        inq.push(make_pair(make_pair(x, y),make_pair(level, 0)));
        vector<pair<int , pair<int, int> > > vp;
        int min_way = 0;
        dp[x][y] = 1;
        while(!inq.empty()){
            int inx = inq.front().first.first, iny = inq.front().first.second;
            int inlevel = inq.front().second.first;
            inq.pop();
            if(map[inx][iny] != 0 && map[inx][iny] < inlevel){
                vp.push_back(make_pair(dp[inx][iny], make_pair(inx,iny)));
            }
            for(int i=0;i<4;i++){
                int mx = inx + dir[i][0], my = iny + dir[i][1];
                if(mx < 0 || my < 0 || mx >= n || my >= n) continue;
                if(map[mx][my] > level) continue;
                if(dp[mx][my] == 0) continue;
                dp[mx][my] += dp[inx][iny];
                inq.push(make_pair(make_pair(mx, my),make_pair(inlevel, way)));
            }
        }
        sort(vp.begin(), vp.end(), cmp);
        inq.push(make_pair(make_pair(vp[0].second.first, vp[0].second.second), make_pair(level+1, way+1)));
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
                bshark.x = i;
                bshark.y = j;
                bshark.level = 2;
            }
        }
    }
    bfs();
    //dfs(bshark.x, bshard.y, bshark.level, 0, 0);
    
    return 0;
}
