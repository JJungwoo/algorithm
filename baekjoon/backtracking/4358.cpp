/*
[boj] 4358. 생태학 
https://www.acmicpc.net/problem/4358
*/

#include <iostream>
#include <cstring>
#include <map>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
string input;
map<string, int> m;
int main() 
{
    io;
    int cnt = 0;
    while(getline(cin, input)) {
        m[input]++;
        cnt++;
    }
    cout.precision(4);
    cout<<fixed;
    for(auto i : m) {
        cout<<i.first<<" "<<((double)i.second/cnt)*100<<"\n";
    }
    return 0;
}