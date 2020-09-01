/*
[boj] 9655. 돌 게임 
https://www.acmicpc.net/problem/9655
*/

#include <iostream>
#include <string>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
string answer[2] = { "CY", "SK" };
int main() 
{
    io;
    int N;
    cin >> N;
    cout<<answer[N % 2]<<"\n";
    return 0;
}