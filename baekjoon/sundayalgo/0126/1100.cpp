/*
[BOJ] 1100. 하얀 칸
*/
#include <iostream>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

char map[9][9];
int ans;

int main()
{
    io;
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            cin>>map[i][j];
            if(i%2){
                if(j%2 == 1 && map[i][j] == 'F') ans++;
            }else{
                if(j%2 == 0 && map[i][j] == 'F') ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}