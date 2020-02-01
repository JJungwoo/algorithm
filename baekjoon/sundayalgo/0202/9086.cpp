/*
[BOJ] 9086. 문자열
*/

#include <iostream>
#include <cstring>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    io;
    int n;
    cin>>n;
    while(n--){
        string str;
        cin>>str;
        cout<<str[0]<<str[str.size()-1]<<"\n";
    }

    return 0;
}
