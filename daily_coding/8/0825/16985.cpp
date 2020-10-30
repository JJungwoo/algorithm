/*
[boj] 16985. Maaaaaaaaaze
https://www.acmicpc.net/problem/16985
*/

#include <iostream>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int INF = 1e9;
int ans = INF;
int map[5][5][5];
void solve() {
    
}
int main() 
{
    io;
    for(int x=0;x<5;x++){
        for(int y=0;y<5;y++){
            for(int z=0;z<5;z++){
                cin>>map[x][y][z];
            }
        }
    }
    solve();
    cout<<ans<<"\n";
    return 0;
}

