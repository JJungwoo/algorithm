/*
[boj] 9661. 돌 게임 7
https://www.acmicpc.net/problem/9661
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;
int main() 
{
    io;
    ll N;
    cin >> N;
    if(N % 5 == 0 || N % 5 == 2) cout<<"CY\n";
    else cout<<"SK\n";
    return 0;
}