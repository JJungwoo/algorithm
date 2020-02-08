/*
[BOJ] 17070. 파이프 옮기기 1
앞에만 봐도 될듯함.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, ans;
int house[16][16];

// 0: 가로, 1: 세로, 2: 대각선

void bfs(){
    queue<pair<pair<int, int>, int> > qp;
    qp.push(make_pair(make_pair(0,1), 0));
    while(!qp.empty()){
        int x = qp.front().first.first, y = qp.front().first.second;
        int dir = qp.front().second;
        //cout<<dir<<"\n";
        if(x == n-1 && y == n-1){
            ans++;
        }
        qp.pop();
        if(dir == 0){
            for(int i=0;i<2;i++){
                if(y+1 >= n || house[x][y+1] == 1) continue;
                if(i == 0) qp.push(make_pair(make_pair(x, y+1), 0));
                else if(i == 1){
                    if(x+1 >= n || house[x+1][y] == 1 || house[x+1][y+1] == 1) continue;
                    qp.push(make_pair(make_pair(x+1,y+1), 2));
                }
            }
        }else if(dir == 1){
            for(int i=0;i<2;i++){
                if(x+1 >= n || house[x+1][y] == 1) continue;
                if(i == 0) qp.push(make_pair(make_pair(x+1, y), 1));
                else if(i == 1){
                    if(y+1 >= n || house[x][y+1] == 1 || house[x+1][y+1] == 1) continue;
                    qp.push(make_pair(make_pair(x+1,y+1), 2));
                }
            }
        }else{ // dir == 2
            for(int i=0;i<3;i++){
                if(i == 0 ){
                    if(y+1 >= n || house[x][y+1] == 1) continue;
                    qp.push(make_pair(make_pair(x, y+1), 0));   
                }
                else if(i == 1){
                    if(x+1 >= n || house[x+1][y] == 1) continue;
                    qp.push(make_pair(make_pair(x+1,y), 1));
                }
                else if(i == 2){
                    if(x+1 >= n || y+1 >= n || house[x+1][y] == 1 || house[x][y+1] == 1 || house[x+1][y+1] == 1) continue;
                    qp.push(make_pair(make_pair(x+1,y+1), 2)); 
                }
            }
        }

    }

}

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>house[i][j];
        }
    }

    bfs();
    cout<<ans<<"\n";

    return 0;
}