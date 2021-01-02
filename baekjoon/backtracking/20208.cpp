/*
[boj] 20208. 진우의 민트초코우유 
https://www.acmicpc.net/problem/20208
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, M, H, ans, my[2];
vector<pair<int, int> > mint;
const int dist(int sx, int sy, int dx, int dy) {
    return abs(sx - dx) + abs(sy - dy);
}
int main() 
{
    io;
    cin >> N >> M >> H;
    mint.push_back(make_pair(0, 0));
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            int val;
            cin >> val;
            if(val == 1) {
                my[0] = i, my[1] = j;
            }else if(val == 2) {
                mint.push_back(make_pair(i, j));
            }
        }
    }
    mint[0].first = my[0], mint[0].second = my[1];
    do {
        int m = M;
        for(int i=1;i<mint.size();i++) {
            int nx = mint[i].first, ny = mint[i].second;
            int diff = dist(mint[i-1].first, mint[i-1].second, nx, ny);
            if(m < diff) break;
            m = m - diff + H;
            if(m >= dist(nx, ny, my[0], my[1]) && ans < i) ans = i;
        }
    } while(next_permutation(mint.begin() + 1, mint.end()));
    cout<<ans<<"\n";
    return 0;
}