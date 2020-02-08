/*
[BOJ] 16236. 아기 상어
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
int dir[4][2] = {{-1, 0},{1, 0},{0, -1},{0, 1}};
int map[20][20];



void bfs(){

}

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    bfs();

    return 0;
}