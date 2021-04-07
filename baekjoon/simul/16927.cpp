/*
[boj] 16927. 배열 돌리기 2
https://www.acmicpc.net/problem/16927
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, M, R;
int arr[301][301];
void solve(int loop) {
    for(int k=0;k<loop;k++) {
        int r = R % (2 * (M-2*k) + 2 * (N-2*k) - 4);
        while(r--) {
            int tmp = arr[k][k];
            for(int i=k;i<M-1-k;i++) {
                arr[k][i] = arr[k][i+1];
            }
            for(int i=k;i<N-1-k;i++) {
                arr[i][M-1-k] = arr[i+1][M-1-k];
            }
            for(int i=M-1-k;i>k;i--) {
                arr[N-1-k][i] = arr[N-1-k][i-1];
            }
            for(int i=N-1-k;i>k;i--) {
                arr[i][k] = arr[i-1][k];
            }
            arr[k+1][k] = tmp;
        }
    }
    
}
int main() 
{
    io;
    cin >> N >> M >> R;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
        }
    }
    
    solve(min(M, N) / 2);
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
