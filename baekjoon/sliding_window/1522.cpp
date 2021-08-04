/*
[boj] 1522. 문자열 교환 
https://www.acmicpc.net/problem/1522
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main() 
{
    io;
    string s; cin >> s;
    int bcnt = 0, answer = 1e9;
    for(int i=0;i<s.size();i++) {
        if (s[i] == 'b') bcnt++;
    }
    for(int i=0;i<s.size();i++) {
        int sum = 0;
        for(int j=i;j<i + bcnt;j++) {
            if (s[(j+1)%s.size()] == 'a') sum++;
        }
        answer = min(answer, sum);
    }
    cout<<answer<<"\n";
    return 0;
}