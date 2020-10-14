/*
[boj] 17143. 낚시왕
https://www.acmicpc.net/problem/17143
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int R, C, M;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
struct shark{
    int x, y, s, d, z;
    bool live;
    shark(int _x, int _y, int _s, int _d, int _z, bool _live) : 
    x(_x), y(_y), s(_s), d(_d), z(_z), live(_live) {}
};
vector<shark> sharks;
struct field{   // 속도, 방향, 크기
    int s, d, z;
    vector<pair<int, int> > shk;    // 상어 크기, 번호
    //field(int _s, int _d, int _z) : s(_s), d(_d), z(_z) {}
};
//vector<pair<int, int> > gmap[101][101];
priority_queue<pair<int, int> > gmap[101][101];
bool cmp(pair<int, int> A, pair<int, int> B) {
    return A.first > B.first;
}
void print_map() {
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            cout<< gmap[i][j].size() << " ";
        }
        cout<<"\n";
    }
}
void move_sharks() {
    vector<shark> tmp;
    for(int i=0;i<sharks.size();i++) {
        if(!sharks[i].live) continue;
        int x = sharks[i].x, y = sharks[i].y;
        int d = sharks[i].d, s = sharks[i].s, z = sharks[i].z;
        cout<<x<<" "<<y<<" "<<d<<" "<<s<<"\n";
        for(int i=0;i<s;i++) {
            int mx = x + dir[d][0], my = y + dir[d][1];
            if(mx < 0 || my < 0 || mx >= R || my >= C) {
                if(d == 0 || d == 2) d++;
                else if(d == 1 || d == 3) d--;
                mx = x + dir[d][0], my = y + dir[d][1];
            }
            x = mx, y = my;
        }
        cout<<x<<" "<<y<<" "<<d<<" "<<s<<"\n";
        gmap[x][y].push(make_pair(z, i));
        sharks[i] = shark(x, y, s, d, z, true);
    }
}
void delete_sharks() {
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++) {
            pair<int, int> top = make_pair(-1, -1);
            while(!gmap[i][j].empty()){
                int idx = gmap[i][j].top().first;
                if(sharks[idx].live == false) 
                    gmap[i][j].pop();
                else {
                    top = gmap[i][j].top();
                    break;
                }
            }
            while(!gmap[i][j].empty()) {
                sharks[gmap[i][j].top().second].live = false;
                gmap[i][j].pop();
            }
            if(top.first != -1) {
                gmap[i][j].push(top);
                sharks[top.second].live = true;
            }
        }
    }
}
int simul() {
    int result = 0;
    print_map();
    for(int j=0;j<1;j++) {
        cout<<"낚시왕 위치 : "<<j<<"\n";
        for(int i=0;i<R;i++) {
            if(gmap[i][j].size() == 1 && sharks[gmap[i][j].top().second].live) {
                result += gmap[i][j].top().first;
                sharks[gmap[i][j].top().second].live = false;
                gmap[i][j].pop();
                break;
            }
        }
        move_sharks();
        print_map();
        delete_sharks();
        print_map();
    }
    return result;
}
void solve() {
    int answer = simul();
    cout << answer << "\n";   
}
int main() 
{
    io;
    cin >> R >> C >> M;
    for(int i=0;i<M;i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        r--, c--, d--;
        gmap[r][c].push(make_pair(z, i));
        sharks.push_back(shark(r, c, s, d, z, true));
    }
    solve();   
    return 0;
}