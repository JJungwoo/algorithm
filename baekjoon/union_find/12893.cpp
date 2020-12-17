/*
[boj] 
https://www.acmicpc.net/problem/
*/

#include <iostream>
#include <unordered_map>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
unordered_map<int, int> relation;
int N, M;
int parent[2001];
void init() {
    for(int i=0;i<=N;i++) {
        parent[i] = i;
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
    parent[q] = p;
}
int main() 
{
    io;
    bool chk = true;
    cin >> N >> M;
    init();
    for(int i=0;i<M;i++) {
        int A, B;
        cin >> A >> B;
        int Ap = find(A), Bp = find(B);
        if(Ap == Bp) chk = false;
        else {
            if(relation.count(Ap) == 0) {
                relation[Ap] = Bp;
            }else{
                uni(relation[Ap], Bp);
                uni(Bp, relation[Ap]);
            }

            if(relation.count(Bp) == 0) {
                relation[Bp] = Ap;
            }else{
                uni(relation[Bp], Ap);
                uni(Ap, relation[Bp]);
            }
        }
    }
    if(chk) cout<<"1\n";
    else cout<<"0\n";
    return 0;
}