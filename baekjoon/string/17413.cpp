/*
[boj] 17413. 단어 뒤집기 2
https://www.acmicpc.net/problem/17413
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main() 
{
    io;
    string S;
    getline(cin, S);
    vector<string> v;
    string tmp = "";
    bool chk = false;
    for(char c : S) {
        if(c == '>' && chk) {
            tmp += c;
            v.push_back(tmp);
            chk = false;
            tmp = "";
        }
        else if(c == '<' && !chk) {
            if(tmp != "") {
                reverse(tmp.begin(), tmp.end());
                v.push_back(tmp);
                tmp = "";
            }
            tmp += c;
            chk = true;
        }
        else if(c == ' ' && !chk) {
            reverse(tmp.begin(), tmp.end());
            tmp += ' ';
            v.push_back(tmp);
            tmp = "";
        }
        else {
            tmp += c;
        }
    }
    if(tmp != "") {
        reverse(tmp.begin(), tmp.end());
        v.push_back(tmp);
    }
    for(auto it : v) {
        cout<<it;
    }
    cout<<"\n";
    
    return 0;
}
