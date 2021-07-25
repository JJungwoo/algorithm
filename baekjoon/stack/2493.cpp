/*
[boj] 2493. 탑
https://www.acmicpc.net/problem/2493
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main() 
{
    io;
    int N; cin >> N;
    vector<int> v(N), ans;
    stack<int> s;
    for(int i=0;i<N;i++) {
        cin >> v[i];
        int find = 0;
        while (!s.empty()) {
            if (v[s.top()] < v[i]) {
                s.pop();
            } else {
                find = s.top() + 1;
                break;
            }
        }
        s.push(i);
        ans.push_back(find);
    }
    for(auto it : ans) {
        cout<<it<<" ";
    }
    return 0;
}
