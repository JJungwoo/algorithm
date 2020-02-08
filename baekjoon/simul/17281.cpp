/*
[BOJ] 17281. 야구
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, start;
int map[9];

void bfs(int idx){
    for(int i=0;i<idx;i++){
        cout<<map[i]<<"\n";
    }
}

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        int map[9];
        for(int j=0;j<9;j++){
            cin>>map[j];
            bfs(j);
        }
    }

    return 0;
}