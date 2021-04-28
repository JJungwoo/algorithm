/*
[boj] 1074. Z
https://www.acmicpc.net/problem/1074
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int dir[3][2] = { {0, 1}, {1, 0}, {1, 1} };
int N, r, c, answer;
void conquer(int x, int y) {
    int nx = x, ny = y;
    int loop = 0;
    do {
        if (r == nx && c == ny) {
            cout<<answer<<"\n";
            exit(0);
        }
        nx = x + dir[loop][0];
        ny = y + dir[loop][1];
        answer++;
    }while(loop++ < 3);
}
void divide(int x, int y, int size) {
    if (size == 2) {
        conquer(x, y);
        return ;
    } else if (!(x <= r && r < x + size &&
                y <= c && c < y + size)) {
        answer += size * size;
        return ;
    }    
    
    divide(x, y, size / 2);
    divide(x, y + size / 2, size / 2);
    divide(x + size / 2, y, size / 2);
    divide(x + size / 2, y + size / 2, size / 2);
}
int main()
{
    io;
    cin >> N >> r >> c;
    divide(0, 0, pow(2, N));
    return 0;
}
