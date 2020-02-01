/*
[BOJ] 1188. 음식 평론가
*/

#include <iostream>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int n,m;
int main()
{
    io;
    cin>>n>>m;
    if(n == 1) cout<<m<<"\n";
    else cout<<m - gcd(n,m)<<"\n";

    return 0;
}