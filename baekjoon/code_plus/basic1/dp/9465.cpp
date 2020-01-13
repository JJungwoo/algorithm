/*
[BOJ] 9465. 스티커
*/
#include <iostream>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int t, n;
int sticker[100001][2];
int dp[100001][2];

int main()
{
    io;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++)
                cin>>sticker[i][j];
        }


    }

    return 0;
}