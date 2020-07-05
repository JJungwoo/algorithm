/*
[boj] 5585. 거스름돈
https://www.acmicpc.net/problem/5585
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, ans;
int main()
{
    io;
    cin>>n;
    n = (1000-n);
    while(1){
        if(n-500 >= 0){
            ans++;
            n-=500;
        }else if(n-100 >= 0){
            ans++;
            n-=100;
        }else if(n-50 >= 0){
            ans++;
            n-=50;
        }else if(n-10 >= 0){
            ans++;
            n-=10;
        }else if(n-5 >= 0){
            ans++;
            n-=5;
        }else if(n-1 >= 0){
            ans++;
            n-=1;
        }else break;
    }    
    cout<<ans<<"\n";   
    return 0;
}