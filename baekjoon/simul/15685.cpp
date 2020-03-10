/*
[boj] 15685. 드래곤 커브
*/
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n,ans;
struct point{
    int x, y, d, g;  
};
point my_point[21];
bool visited[101][101];
void solve(){
    for(int i=0;i<n;i++){

    }
    check_square();
}
void check_square(){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(visited[i][j] && visited[i+1][j+1] &&
            visited[i+1][j] && visited[i][j+1]){
                ans++;
            }
        }
    }
}
int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>my_point[i].x>>my_point[i].y>>my_point[i].d>>my_point[i].g;
    }
    solve();
    cout<<ans<<"\n";

    return 0;
}