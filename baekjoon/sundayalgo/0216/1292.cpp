/*
[BOJ] 1292. 쉽게 푸는 문제
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int a, b, ans, ep = 0;
int main()
{
    io;
    cin>>a>>b;
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=i;j++){
            if(i >= a && ep <= b){
                ans += i;
            }
            ep++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}