/*
[BOJ] 10157. 자리배정
*/

#include <iostream>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int c,r,k,x,y,dir,go,stand,cnt;
int movement[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int main()
{
    io;
    cin>>c>>r>>k;
    x = 1, y = 1, go = 1, stand = c, cnt = 1;
    for(int i=1;i<=k+1;i++){
        x += movement[dir][1];  // 가로
        y += movement[dir][0];  // 세로
        
        if()

        cout<<x<<" "<<y<<" dir: "<<dir<<" go:"<<go<<" stand:"<<stand<<" cnt:"<<cnt<<"\n";
        //" lx:"<<limitx<<" ly:"<<limity<<"\n";
    }
    cout<<x<<" "<<y<<"\n";
    return 0;
}