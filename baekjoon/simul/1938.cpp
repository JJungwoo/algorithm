/*
[BOJ] 14889. 스타트와 링크
*/

#include <iostream>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
char map[51][51];

struct wood{
    int x,y;
    int dir;
};

wood my;

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(){

}

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
            if(map[i][j] == 'B'){
                if(i+1 < n || i-1 > 0 || j+1<n || j-1 > 0){
                    if(map[i+1][j] == 'B' || map[i-1][j] == 'B'){
                        my.x = i;
                        my.y = j;
                        my.dir = 1;
                    }
                    else if(map[i][j+1] == 'B' || map[i][j-1] == 'B'){
                        my.x = i;
                        my.y = j;
                        my.dir = -1;
                    }
                }
            }
        }
    }

    bfs();    

    return 0;
}