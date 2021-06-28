/*
[boj] 1342. 행운의 문자열
https://www.acmicpc.net/problem/1342
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int ans;
unordered_set<string> s;
int main() 
{
    io;
    string input;
    cin >> input;
    sort(input.begin(), input.end());
    do {
        bool chk = false;
        for(int i=1;i<input.size();i++) {
            if(input[i] == input[i-1]) {
                chk = true;
                break;
            }
        }
        if(!chk) ans++;
    } while(next_permutation(input.begin(), input.end()));
    cout<<ans<<"\n";
    return 0;
}