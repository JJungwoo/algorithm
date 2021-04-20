/*
[boj] 9375. 패션왕 신해빈
https://www.acmicpc.net/problem/9375
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define NO_CLOTHES 1
int T, N;
int main() {
    cin >> T;
    while(T--) {
        unordered_map<string, int> m;
        cin >> N;
        string clothes, kind;
        while(N--) {
            cin >> clothes >> kind;
            m[kind]++;
        }
        int answer = 1;
        for(auto it : m) {
            answer *= it.second + 1;
        }
        cout << answer - NO_CLOTHES << "\n";
    }
    return 0;
}