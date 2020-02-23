/*
[BOJ] 17837. 새로운 게임2
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, k, ans;
vector<pair<pair<int, int>, pair<int, int> > > vp;  // row, column, dir
/*struct horse{
    int x, y, color, dir; // 1, 2, 3, 4
    horse(int _x, int _y, int _color, int _dir){};
};*/
int map[12][12];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

void solve()
{
    int routine = 1000;
    int turn = vp.size() - 1;
    while(routine){
        int x = vp[turn].first.first + dir[vp[turn].second.first][0];
        int y = vp[turn].first.second + dir[vp[turn].second.first][1];

        if(x < 0 || y < 0 || x >= n || y >= n)
        {
            
        }

        turn = (turn + 1) % vp.size();
        routine--;
    }
    if(routine <= 0)
        cout<<"-n";
    else 
        cout<<ans<<"\n";
}

int main()
{
    io;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        } 
    }
    for(int i=1;i<=k;i++){
        int a,b,c;
        cin>>a>>b>>c;
        vp.push_back(make_pair(make_pair(a-1,b-1), make_pair(c-1,i)));
    }
    solve();
    return 0;
}