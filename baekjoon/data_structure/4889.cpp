/*
[boj] 4889. 안정적인 문자열
https://www.acmicpc.net/problem/4889
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int do_check_safe_str(string str) {
    if(str.length() == 0) return 0;
    stack<char> s;
    int answer = 0;
    for(int i=0;i<str.length();i++) {
        if(str[i] == '{') s.push(str[i]);
        else if(!s.empty() && s.top() == '{') {
            s.pop();
        }
        else {
            s.push('{');
            answer++;
        }
    }
    return answer + s.size() / 2;
}

int main() 
{
    io;
    int idx = 1;
    string input;
    while(true) {
        cin >> input;
        if(input[0] == '-') break;
        cout<<idx++<<". "<<do_check_safe_str(input)<<"\n";
    }
    return 0;
}
