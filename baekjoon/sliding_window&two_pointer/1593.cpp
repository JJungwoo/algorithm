/*
[boj] 1593. 문자 해독
https://www.acmicpc.net/problem/1593
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define MAX_VAL 3000
int g, s, answer;
string W, S;
unordered_map<char, int> m;
int main() 
{
    io;
    cin >> g >> s;
    cin >> W;
    cin >> S;

    for(auto it : W) {
        if (m.count(it) == 0) {
            m[it] = MAX_VAL;
        }
        m[it]++;
    }
    unordered_map<char, int> tm = m;
    for(int i=0;i<g - 1;i++) {
        if (tm.count(S[i]) > 0) {
            tm[S[i]]--;
        }
    }

    for(int i=g - 1;i<s;i++) {
        if (m.count(S[i]) > 0) {
            if (tm.find(S[i]) == tm.end())
                tm[S[i]] = MAX_VAL;
            else if (tm.count(S[i]) > 0) {
                tm[S[i]]--;
                if (tm[S[i]] == MAX_VAL) {
                    tm.erase(S[i]);
                }
            }
        }
        
        if (tm.size() == 0) {
            answer++;
        }
        
        if (m.count(S[i - (g - 1)]) > 0) {
            tm[S[i - (g - 1)]]++;
            if (tm.find(S[i - (g - 1)]) == tm.end())
                tm[S[i - (g - 1)]] = MAX_VAL;
            else if (tm[S[i - (g - 1)]] == MAX_VAL) 
                tm.erase(S[i - (g - 1)]);
        }
    }
    cout<<answer<<"\n";
    return 0;
}
