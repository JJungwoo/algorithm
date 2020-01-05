/*
[BOJ] 2702. 초6 수학
최소공배수, 최대공약수
*/
#include <iostream>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int t;

int gcd(int a, int b){
    if(a%b == 0) return b;
    return gcd(b, a%b);
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}

int main()
{
    io;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        cout<<lcm(a,b)<<" "<<gcd(a,b)<<"\n";
    }
    return 0;
}