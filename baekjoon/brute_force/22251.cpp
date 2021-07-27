/*
[boj] 22251. 빌런 호석
https://www.acmicpc.net/problem/22251
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
vector<vector<int>> num_map = 
{
    { 1, 1, 1, 1, 1, 1, 0}, // 0
    { 0, 0, 1, 1, 0, 0, 0},
    { 0, 1, 1, 0, 1, 1, 1},
    { 0, 1, 1, 1, 1, 0, 1},
    { 1, 0, 1, 1, 0, 0, 1},
    { 1, 1, 0, 1, 1, 0, 1},
    { 1, 1, 0, 1, 1, 1, 1},
    { 0, 1, 1, 1, 0, 0, 0},
    { 1, 1, 1, 1, 1, 1, 1},
    { 1, 1, 1, 1, 1, 0, 1}  // 9
};
int main() 
{
    io;
    int N, K, P, X, ans = 0; 
    cin >> N >> K >> P >> X;
    for(int i=1;i<=N;i++) {
        if (X == i) {
            continue;
        } else {
            int sum = 0;
            int A = i, B = X;
            for(int j=0;j<K;j++) {
                for(int z=0;z<7;z++) {
                    if (num_map[A % 10][z] != num_map[B % 10][z])
                        sum++;
                }
                A /= 10;
                B /= 10;
            }
            if (sum <= P) {
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
