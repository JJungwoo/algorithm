/*
[boj] 1918. 후위표기식
https://www.acmicpc.net/problem/1918
*/

#include <iostream>
#include <string>
#include <stack>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
string input, answer;
stack<char> s;
inline int priority(char c) {
    if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return 0;
}
int main() 
{
    io;
    cin >> input;
    for(auto c : input) {
        if(c == '(') { s.push(c); continue; }
        else if(c == ')') { 
            while(!s.empty() && s.top() != '(') {
                answer.push_back(s.top());
                s.pop();
            }
            s.pop();
            continue;
        }
        int cur = priority(c);
        if(cur > 0) {
            if(s.size() >= 1) {
                char before = s.top();
                if(cur <= priority(before)) {
                    while(!s.empty()) {
                        if(cur > priority(s.top())) break;
                        answer.push_back(s.top());
                        s.pop();
                    }
                }
            }
            s.push(c);
        }
        else answer.push_back(c);
    }
    while(!s.empty()) {
        answer.push_back(s.top());
        s.pop();
    }
    cout<<answer<<"\n";
    return 0;
}