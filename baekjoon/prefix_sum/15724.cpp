/*
[boj] 15724. 주지수
https://www.acmicpc.net/problem/15724
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, M, K;
int area[1025][1025], psum[1025][1025];
int main()
{
    io;
    cin >> N >> M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin >> area[i][j];
            psum[i][j] = area[i][j] - psum[i-1][j-1] + psum[i-1][j] + psum[i][j-1];
        }
    }
    cin >> K;
    while(K--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout<<psum[x2][y2] - (psum[x1-1][y2] + psum[x2][y1-1] - psum[x1-1][y1-1])<<"\n";
    }
    return 0;
}