/*
[boj] 4195. 친구 네트워크
https://www.acmicpc.net/problem/4195
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int parent[200010], cnt[200010];
int T, F;
unordered_map<string, int> m;
void init(int n) {
    for(int i=0;i<2 * n;i++) {
        parent[i] = i;
        cnt[i] = 1;
    }
}
int find(int p) {
    if(parent[p] == p) return p;
    else return parent[p] = find(parent[p]);
}
int uni(int p, int q) {
    p = find(p);
    q = find(q);
    if(p != q) {
        parent[q] = p;
        cnt[p] += cnt[q];
        cnt[q] = 1;
    }
    return cnt[p];
}
int main() 
{
    io;
    cin >> T;
    while(T--) {
        int idx = 0;
        m.clear();
        cin >> F;
        init(F);
        for(int i=0;i<F;i++) {
            string A, B;
            cin >> A >> B;
            if(m.find(A) == m.end())
                m[A] = idx++;
            if(m.find(B) == m.end())
                m[B] = idx++;
            cout<<uni(m[A], m[B])<<"\n";
        }
    }
    return 0;
}
