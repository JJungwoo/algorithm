/*
[BOJ] 1699. 제곱수의 합
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main()
{
    io;
    int cnt = 0, n; cin>>n;
    int s = sqrt(n);    // ex) n = 11, s = 2;
    for(int i=s;i>0;i--){
        if(n-i > i){
            n -= i;
            i+=1;
            cnt++;
        }else{
            n -= i;
            cnt++;
        }
    }
    cout<<cnt<<"\n";
    return 0;
}