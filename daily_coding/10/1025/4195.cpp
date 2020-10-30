/*
[boj] 4195. 친구 네트워크 
https://www.acmicpc.net/problem/4195
*/

#include <iostream>
#include <unordered_map>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int T, F;
int parent[100001], cnt[100001];
void init(int *tmp, int count) {
    for(int i=0;i<=count;i++) {
        tmp[i] = i;
        cnt[i] = 1;
    }
}
int find(int p) {
    if(parent[p] == p) return p;
    else return parent[p] = find(parent[p]);
}
void uni(int p, int q) {
    p = find(p);
    q = find(q);
    if(p == q) return;
    parent[p] = q;
    cnt[q] += cnt[p];
}
int main() 
{
    io;
    cin >> T;
    while(T--) {
        unordered_map<string, int> umap;
        int idx = 1;
        cin >> F;
        init(parent, F);
        for(int i=0;i<F;i++) {
            string A, B;
            cin >> A >> B;
            if(umap.count(A) == 0) {
                umap[A] = idx;
                idx++;
            }
            if(umap.count(B) == 0) {
                umap[B] = idx;
                idx++;
            }
            uni(umap[A], umap[B]);
            cout<<max(cnt[parent[umap[A]]], cnt[parent[umap[B]]])<<"\n";
        }
    }
    return 0;
}