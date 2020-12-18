/*
[boj] 2661. 좋은수열
https://www.acmicpc.net/problem/2661
*/

#include <iostream>
#include <string>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N;
bool isSuccess(string tmp) {
    int cur = tmp.length() - 1;
    for(int i=1;i<=tmp.length()/2;i++) {
        string a = tmp.substr(cur - i, i);
        string b = tmp.substr(cur, i);
        if(a == b) return false;
        cur--;
    }
    return true;
}
void solve(string seq) {
    if(!isSuccess(seq)) return;
    if(seq.length() == N) {
        cout<<seq<<"\n";
        exit(0);
    }

    solve(seq+'1');
    solve(seq+'2');
    solve(seq+'3');
}
int main() 
{
    io;
    cin >> N;
    solve("1");
    solve("2");
    solve("3");
    return 0;
}