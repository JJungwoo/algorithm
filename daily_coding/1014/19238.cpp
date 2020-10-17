/*
[boj] 19238. 스타트 택시 
https://www.acmicpc.net/problem/19238
*/

#include <iostream>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int N, M, K;
int map[21][21], car[2];
struct customer {
    int sx, sy, dx, dy;
    customer(int _sx, int _sy, int _dx, int _dy) : sx(_sx), sy(_sy), dx(_dx), dy(_dy) {}
};
vector<customer> customers;
void solve() {
    int answer = -1;
    
}
int main() 
{
    io;
    cin >> N >> M >> K;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) map[i][j] = -1;
        }
    }
    cin >> car[0] >> car[1];
    car[0]--, car[1]--;
    for(int i=0;i<M;i++) {
        int sx, sy, dx, dy;
        cin >> sx >> sy >> dx >> dy;
        customers.push_back(customer(sx-1, sy-1, dx-1, dy-1));
    }
    solve();
    return 0;
}