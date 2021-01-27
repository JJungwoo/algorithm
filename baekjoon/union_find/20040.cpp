/*
[boj] 20040. 사이클 게임
https://www.acmicpc.net/problem/20040
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, M, parent[500001];
int find(int p) {
    if (parent[p] == p) return p;
    else return parent[p] = find(parent[p]);
}
void uni(int p, int q) {
    p = find(p);
    q = find(q);
    if(q == p) return;
    if(q > p) parent[q] = p;
    else parent[p] = q;
}
int main()
{
    io;
    int ans = 0;
    cin >> N >> M;
    for(int i=0;i<=N;i++) parent[i] = i;
    for(int i=1;i<=M;i++) {
        int A, B;
        cin >> A >> B;
        if(ans != 0) continue;
        if(find(A) == find(B))
            ans = i;
        else
            uni(A, B);
    }
    cout<<ans<<"\n";
    return 0;
}