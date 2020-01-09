/*
[BOJ] 3085. 사탕 게임
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n,ans;
char candy[51][51];

void find_eat(){
    int acnt, bcnt, res = 0;
    for(int i=0;i<n;i++){
        acnt = 1, bcnt = 1;
        for(int j=0;j<n-1;j++){
            if(candy[i][j] == candy[i][j+1]) acnt++;
            else acnt = max(acnt, res), acnt = 1;
            if(candy[j][i] == candy[j+1][i]) bcnt++;
            else bcnt = max(bcnt, res), bcnt = 1;
            res = acnt > bcnt ? acnt : bcnt;
            if(res > ans) ans = res;
        }
    }
}

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>candy[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            // 가로
            swap(candy[j][i], candy[j+1][i]);
            find_eat();
            swap(candy[j][i], candy[j+1][i]);
            
            // 세로
            swap(candy[i][j], candy[i][j+1]);
            find_eat();
            swap(candy[i][j], candy[i][j+1]);
        }
    }
    cout<<ans<<"\n";
    return 0;
}