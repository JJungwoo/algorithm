/*
[boj] 2869. 달팰이는 올라가고 싶다.
https://www.acmicpc.net/problem/2869
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;
ll mid, a, b, v;
int main()
{
    io;
    cin>>a>>b>>v;
    ll left = 0, right = 1000000000;
    while(left < right){
        mid = (left + right)/2;
        if((mid-1) * (a-b) + a >= v){
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    cout<<right<<"\n";
    return 0;
}