/*
[BOJ] 1913. 달팽이
*/
#include <iostream>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, find, cnt = 1;
int map[1000][1000];
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0. -1}};

int main()
{
    io;
    cin>>n;
    cin>>find;
    int x = n - n/2 - 1, y = n - n/2 - 1;
    for(int i=0;i<n * n;i++){
        for(int j=0;j<4;j++){
            if(j%2 != 0) cnt++;
            map[x+dir[j][0]][y+dir[j][1]] = cnt;
        }
    }
    return 0;
}