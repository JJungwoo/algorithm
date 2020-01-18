/*
[BOJ] 1051. 숫자 정사각형
*/
#include <iostream>
#include <vector>
using namespace std;

int n, m;
int map[51][51];
int dir[3][2] = {{0,1}, {-1,0}, {0,-1}};

void dfs(int x, int y)
{


}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d", &map[i][j]);
        }
    }

    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            dfs(i,j);
        }
    }
    
    return 0;
}