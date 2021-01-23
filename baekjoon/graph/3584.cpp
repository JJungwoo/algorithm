/*
[boj] 3584. 가장 가까운 공통 조상
https://www.acmicpc.net/problem/3584
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int ans;
vector<int> v[10001];
set<int> s;
void find_root(int cur) {
    if (s.find(cur) == s.end())
        s.insert(cur);
    else {
        ans = cur;
        return;
    }

    for(auto it : v[cur]) {
        find_root(it);
    }
}
int main()
{
    io;
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        for(int i=1;i<=N;i++)
            v[i].clear();
        N--;
        while(N--) {
            int A, B;
            cin >> A >> B;
            v[B].push_back(A);
        }
        ans = 0;
        s.clear();
        int A, B;
        cin >> A >> B;
        find_root(A);
        find_root(B);
        cout<<ans<<"\n";
    }
    return 0;
}
