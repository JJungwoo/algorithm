/*
[boj] 1662. 압축
https://www.acmicpc.net/problem/1662
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
string S;
stack<int> st;
int visited[50];
int solve(int s, int e) {
    int res = 0;
    for(int i=s;i<e;i++) {
        if(S[i] == '(') {
            int cnt = S[i-1] - '0';
            res += cnt * solve(i+1, visited[i]) - 1;
            i = visited[i];
            continue;
        }
        res++;
    }
    return res;
}
int main()
{
    io;
    cin >> S;
    for(int i=0;i<S.length();i++) {
        if(S[i] == '(') st.push(i);
        else if(S[i] == ')') {
            visited[st.top()] = i;
            st.pop();
        }
    }
    cout<<solve(0, S.length())<<"\n";
    return 0;
}