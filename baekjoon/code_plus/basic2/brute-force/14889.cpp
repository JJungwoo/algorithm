/*
[BOJ] 14889. 스타트와 링크
*/

#include <iostream>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, ans = 101;
int score[21][21];
int sum[21][21];

void dfs(int x, int y){

}

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>score[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum[i][j] = score[i][j] + score[j][i];
        }
    }
    cout<<"\n";
   for(int i=0;i<n;i++){
        for(int j=i;j<n-1;j++){
            if(sum[i][j] != 0){
                int diff = abs(sum[i][j] - sum[i][j-1]);
                if(ans > diff) ans = diff;
            }
        }
        cout<<"\n";
    }
     

    cout<<ans<<"\n";
    return 0;
}