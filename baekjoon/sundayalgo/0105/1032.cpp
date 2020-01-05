/*
[BOJ] 1032. 명령 프롬프트
*/
#include <iostream>
#include <cstring>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
string str[51];
string check;

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str[i];
    }
    str[0].copy(check, sizeof(str[0]), 0);
    cout<<check<<"\n";
    for(int i=0;i<n;i++){
        cout<<str[i]<<"\n";

    } 
    return 0;
}