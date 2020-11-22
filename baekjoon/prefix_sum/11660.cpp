/*
[boj] 11660. 구간 합 구하기 5
https://www.acmicpc.net/problem/11660
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, M;
int arr[1025][1025], psum[1025][1025];
void find_prefix_sum() {
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            psum[i][j] = psum[i-1][j] + psum[i][j-1] + arr[i][j] - psum[i-1][j-1];
        }
    }
}
int main()
{
    io;
    cin >> N >> M;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin >> arr[i][j];
        }
    }
    find_prefix_sum();
    for(int i=0;i<M;i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout<<psum[x2][y2] + psum[x1-1][y1-1] - psum[x1-1][y2] - psum[x2][y1-1]<<"\n";
    }
    return 0;
}