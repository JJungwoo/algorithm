/*
[BOJ] 2630. 색종이 만들기
*/

#include <iostream>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, bans, wans;
int cpaper[128][128];

void solve(int x, int y, int square)
{
    bool check = true;
    int check_color = cpaper[x][y];
    for(int i=x;i<x+square;i++){
        for(int j=y;j<y+square;j++){
            if(cpaper[i][j] != check_color) {
                check = false;
                break;
            }
        }
    }
    if(!check){
        int div = square/2;
        solve(x, y, div);
        solve(x+div, y, div);
        solve(x, y+div, div);
        solve(x+div, y+div, div);
    }else {
        check_color == 1 ? bans++ : wans++;
    }
}

int main()
{   
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cpaper[i][j];
        }
    }

    solve(0, 0, n);
    cout<<wans<<"\n";
    cout<<bans<<"\n";
    return 0;
}