/*
[boj] 1593. 문자 해독
https://www.acmicpc.net/problem/1593
*/
#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define MAX_VAL 52
int g, s, answer;
string W, S;
int answer_array[MAX_VAL], interval_array[MAX_VAL];
inline int alpabet_to_int(char c) {
    return (int)(c <= 'Z' ? c - 'A' : c - 'a' + 26);
}
inline bool check_answer_array() {
    for(int i=0;i<MAX_VAL;i++) {
        if (answer_array[i] != interval_array[i]) {
            return false;
        }
    }
    return true;
}
int main() 
{
    io;
    cin >> g >> s;
    cin >> W;
    cin >> S;
    for(int i=0;i<g;i++) {
        answer_array[alpabet_to_int(W[i])]++;
        interval_array[alpabet_to_int(S[i])]++;
    }
    if (check_answer_array())
            answer++;

    for(int i=g;i<s;i++) {
        interval_array[alpabet_to_int(S[i-g])]--;
        interval_array[alpabet_to_int(S[i])]++;
        
        if (check_answer_array())
            answer++;
    }
        
    cout<<answer<<"\n";
    return 0;
}