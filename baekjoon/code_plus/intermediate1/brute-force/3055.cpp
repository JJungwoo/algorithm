/*
[BOJ] 3055. 탈출
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int r, c, ans;
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
char map[50][50];
bool visited[50][50];

struct obj{
    int x, y;
    char t;
};

obj d, s, w;
queue<pair<pair<int, int>, int> > s_qp;
queue<pair<int, int> > wqp;
//vector<pair<int, int> > s_vp;

void print_map(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void print_queue(queue<pair<pair<int, int>, int> > q){
    cout<<"print_queue\n";
    while(!q.empty()){
        cout<<q.front().first.first<<","<<q.front().first.second<<"\n";
        q.pop();
    }
    //cout<<q.front().first.first<<","<<q.front().first.second<<"\n";
}

void solve()
{
    while(!wqp.empty() || !s_qp.empty()){
        //cout<<"!\n";
        int wqsize = wqp.size();
        for(int z=0;z<wqsize;z++){
            int x = wqp.front().first, y = wqp.front().second;
            wqp.pop();
            for(int i=0;i<4;i++){
                int mx = x + dir[i][0], my = y + dir[i][1];
                //cout<<"mx:"<<mx<<",my:"<<my<<"\n";
                if(mx < 0 || my < 0 || mx >= r || my >= c) continue;
                if(map[mx][my] == 'D') continue; 
                if(map[mx][my] == 'X') continue;
                if(map[mx][my] == '*') continue;
                map[mx][my] = '*';
                wqp.push(make_pair(mx,my));
            }
        }
        //print_map();
        int qsize = s_qp.size();
        //cout<<"qsize:"<<qsize<<"\n";
        for(int i=0;i<qsize;i++){
            int sx = s_qp.front().first.first, sy = s_qp.front().first.second;
            visited[sx][sy] = true;
            //cout<<"sx:"<<sx<<",sy:"<<sy<<" dx:"<<d.x<<" dy:"<<d.y<<"\n";
            int cnt = s_qp.front().second;
            if(sx == d.x && sy == d.y){
                ans = cnt;
                return;
            }
            s_qp.pop();
            for(int j=0;j<4;j++){
                int smx = sx + dir[j][0], smy = sy + dir[j][1];
                if(smx < 0 || smy < 0 || smx >= r || smy >= c) continue;
                if(map[smx][smy] == '*' || map[smx][smy] == 'X') continue;
                if(visited[smx][smy]) continue;
                visited[smx][smy] = true;
                s_qp.push(make_pair(make_pair(smx,smy), cnt+1));
            }
            //cout<<"s_qp.size:"<<s_qp.size()<<"\n";
            //print_queue(s_qp);
        }
    }
}

int main()
{
    io;
    cin>>r>>c;
    w.x = -1;
    w.y = -1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>map[i][j];
            if(map[i][j] == 'D'){
                d.x = i, d.y = j, d.t = 'D';
            }else if(map[i][j] == 'S'){
                s.x = i, s.y = j, s.t = 'S';
                s_qp.push(make_pair(make_pair(i, j), 0));
            }else if(map[i][j] == '*'){
                wqp.push(make_pair(i, j));
                //w_vp.push_back(make_pair(w.x, w.y));
            }
        }
    }
    solve();
    //dfs(s.x, s.y, 0, w_vp);
    if(ans != 0) cout<<ans<<"\n";
    else cout<<"KAKTUS\n";
    
    return 0;
}