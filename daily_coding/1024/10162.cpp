/*
[boj] 10162. 전자레인지 
https://www.acmicpc.net/problem/10162
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int T, A, B, C;
int value[3] = { 300, 60, 10 };
int main() 
{
    io;
    cin >> T;
    if(T >= value[0]) {
       A = T / value[0];
       T %= value[0];
    }
    if(T >= value[1]) {
        B = T / value[1];
        T %= value[1];
    }
    if(T >= value[2]) {
        C = T / value[2];
        T %= value[2];
    }
    if(T != 0) cout<<"-1\n";
    else cout<<A<<" "<<B<<" "<<C<<"\n";
    return 0;
}