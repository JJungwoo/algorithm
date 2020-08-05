/*
[boj] 15972. 물탱크
https://www.acmicpc.net/problem/15972
*/

#include <iostream>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n,m,h,ans;
struct box{
    int a,b,c,d;
};
vector<box> boxs;
int main()
{
    io;
    cin>>n>>m>>h;
    boxs.resize(n*m+1);
    // 가로
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m;j++){
            int input;
            cin>>input;
            boxs[j].a = input;
        }
    }
    // 세로
    for(int i=0;i<n;i++){
        for(int j=0;j<m+1;j++){

        }
    }


    return 0;
}