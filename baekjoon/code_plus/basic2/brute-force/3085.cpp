/*
[BOJ] 3085. 사탕 게임
*/
#include <iostream>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n,ans;
char candy[51][51];
inline void myswap(int &a, int &b) { int tmp = a; a = b; b = tmp; }

void find_eat(int x, int y, int chk){
    if(chk){    // 가로
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(candy[x][y] == candy[x][i]) cnt++;
            else cnt = 0;
            if(cnt > ans) ans = cnt;
        }        
    }else {
       int cnt = 0;
        for(int i=0;i<n;i++){
            if(candy[x][y] == candy[i][y]) cnt++;
            else cnt = 0;
            if(cnt > ans) ans = cnt;
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
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            // 가로
            swap(candy[i][j], candy[i+1][j]);
            find_eat(i,j,1);
            swap(candy[i][j], candy[i+1][j]);
            swap(candy[i][j], candy[i][j+1]);
            find_eat(i,j,1);
            swap(candy[i][j], candy[i][j+1]);
            // 세로
            swap(candy[i][j], candy[i][j+1]);
            find_eat(i,j,0);
            swap(candy[i][j], candy[i][j+1]);
            swap(candy[i][j], candy[i+1][j]);
            find_eat(i,j,0);
            swap(candy[i][j], candy[i+1][j]);
        }
    }
    cout<<ans<<"\n";
    return 0;
}