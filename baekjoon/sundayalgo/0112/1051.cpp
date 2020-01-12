/*
[BOJ] 1051. 숫자 정사각형
*/
#include <iostream>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, m;
int map[51][51];

int main()
{
    io;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d", &map[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            for(int z=j+1;z<m;z++){
                if(map[i][j] == map[i][z]){
                    int diff = z - j;
                }
            }
        }
    }
    
    return 0;
}