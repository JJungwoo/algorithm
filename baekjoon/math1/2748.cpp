/*
[boj] 2748. 피보나치 수 2
https://www.acmicpc.net/problem/2748
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;
int n;
ll fibo(int n){
    ll a = 0, b = 1, tmp = 0;
    for(int i=0;i<n;i++){
        tmp = a+b;
        a = b;
        b = tmp;
    }
    return a;
}
int main()
{
	io;
    cin>>n;
    cout<<fibo(n)<<"\n";   
	return 0;
}
