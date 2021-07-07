  
/*
[programmers] 짝지어 제거하기
https://programmers.co.kr/learn/courses/30/lessons/12973
*/
#include <bits/stdc++.h>
using namespace std;
int couple_remove(string s) {
    stack<char> st;
    for(int i=s.size();i>=0;i--) {
        if (!st.empty() && st.top() == s[i]) {
            st.pop();
        } else {
            st.push(s[i]);
        }
    }
    char tmp = st.top(); st.pop();
    while(!st.empty()) {
        if (st.top() == tmp) {
            st.pop();
            if (!st.empty()) tmp = st.top();
        } else break;
    }
    return st.size() == 0 ? 1 : 0;
}
int solution(string s)
{
    int answer = 0;
    return answer + couple_remove(s);
}
