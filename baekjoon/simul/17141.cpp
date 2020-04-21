/*
[BOJ] 17141. 연구소 2
*/

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int n, m, ans = 987654321;
int map[50][50], copymap[50][50];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
bool visited[50][50];
vector<pair<int, int> > virus;
void copy_map(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            copymap[i][j] = map[i][j];
        }
    }
}
void print(){
    cout<<"print\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<copymap[i][j]<<" ";
        }
        cout<<"\n";
    }
 
}
int bfs(){
    int maxcnt = 0;
    queue<pair<pair<int, int>,int > > q;
    int vsize = virus.size();
    bool vv[50][50];
    memset(vv, 0, sizeof(vv));
    copy_map();
    for(int i=0;i<vsize;i++){
        copymap[virus[i].first][virus[i].second] = 0;
        q.push(make_pair(make_pair(virus[i].first, virus[i].second), 0));
        vv[virus[i].first][virus[i].second] = true;
    }
    while(!q.empty()){
        int x = q.front().first.first, y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        if(maxcnt < cnt){
            maxcnt = cnt;
        }
        for(int i=0;i<4;i++){
            int mx = x + dir[i][0], my = y + dir[i][1];
            if(mx < 0 || my < 0 || mx >= n || my >= n) continue;
            if(map[mx][my] != 0) continue;
            if(vv[mx][my]) continue;
            copymap[mx][my] = cnt+1;
            vv[mx][my] = true;
            q.push(make_pair(make_pair(mx, my), cnt+1));
        }
    }
    //print();
    return maxcnt;
}
void solve(int cnt){
    if(cnt == m){
        int tmp = bfs();
        if(ans > tmp){
            ans = tmp;
        }
        return;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]) continue;
            if(map[i][j] == -1) continue;
            visited[i][j] = true;
            virus.push_back(make_pair(i, j));
            solve(cnt+1);
            virus.pop_back();
            visited[i][j] = false;
        }
    }
}
int main()
{
    io;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
            if(map[i][j] == 1) map[i][j] = -1;
        }
    }
    solve(0);
    if(ans == 987654321) cout<<"-1\n";
    else cout<<ans<<"\n";
    return 0;
}