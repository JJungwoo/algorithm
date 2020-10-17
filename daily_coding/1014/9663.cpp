/*
[boj] 9663. N-Queen 
https://www.acmicpc.net/problem/9663
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int dir[8][2] = { {-1, 0}, {-1, 1}, {0, 1} ,{1, 1} ,{1, 0} ,{1, -1} ,{0, -1} ,{1, -1} };
int N, answer;
bool map[16][16];
void dfs(int cnt) {
    if(cnt == N) {
        answer++;
        return;
    }

    for(int i=0;i<N;i++) {
        for(int d=0;d<8;d++)
            if(map[cnt][i] || map[])
        map[cnt][i] = true;
        dfs(cnt + 1);
        map[cnt][i] = false;
    }
}
int main() 
{
    io;
    cin >> N;
    dfs(0);
    cout << answer << "\n";
    return 0;
}