/*
[boj] 11050. 이항 계수1
https://www.acmicpc.net/problem/11050
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;
int n, k;
ll factorial(int start, int reply){
    ll res = 1;
    for(int i=start;i>start-reply;i--){
        res *= i;
    }
    return res;
}
int main()
{
	io;
    cin>>n>>k;
    cout<<(factorial(n, k)/factorial(k, k))<<"\n";
	return 0;
}
