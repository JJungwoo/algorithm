/*
[boj] 17406. 배열 돌리기 4
https://www.acmicpc.net/problem/17406
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int MAX_INT = 1e9;
const int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int N, M, K, answer = MAX_INT;
int A[51][51], B[51][51];
bool visited[6];
struct rule{
    int r, c, s;
};
vector<rule> rules, v;
static inline int row_sum() {
    int ret = MAX_INT;
    for(int i=0;i<N;i++) {
        int sum = 0;
        for(int j=0;j<M;j++) {
            sum += B[i][j];
        }
        ret = min(ret, sum);
    }
    return ret;
}
void do_spin(int x, int y, int size) {
    for(int i=1;i<=size;i++) {
        int sx = x - i, sy = y - i;
        int tmp = B[sx][sy], d = 0;
        do{
            if(sx + dir[d][0] < x-i || sy + dir[d][1] < y-i || 
                sx + dir[d][0] > x+i || sy + dir[d][1] > y+i) d++;
            B[sx][sy] = B[sx+dir[d][0]][sy+dir[d][1]];
            sx = sx+dir[d][0];
            sy = sy+dir[d][1];
        }while(!(sx == x-i && sy == y-i));
        B[sx][sy+1] = tmp;
    }
}
void solution(int idx) {
    if(rules.size() == idx) {
        memcpy(B, A, sizeof(A));
        for(auto it : v) {
            do_spin(it.r, it.c, it.s);
        }
        int cnt = row_sum();
        answer = min(answer, cnt);
        return ;
    }

    for(int i=0;i<rules.size();i++) {
        if(visited[i]) continue;
        visited[i] = true;
        v.push_back(rules[i]);
        solution(idx+1);
        v.pop_back();
        visited[i] = false;
    }
}
int main() 
{
    io;
    cin >> N >> M >> K;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> A[i][j];
        }
    }
    while(K--) {
        int r, c, s;
        cin >> r >> c >> s;
        rules.push_back({r-1, c-1, s});
    }
    solution(0);
    cout<<answer<<"\n";
    return 0;
}