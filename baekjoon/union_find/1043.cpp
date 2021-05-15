/*
[boj] 1043. 거짓말
https://www.acmicpc.net/problem/1043
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, M, ans;
int parent[51], known[51];
vector<int> v[51];
void init() {
    for(int i=0;i<=N;i++) {
        parent[i] = i;
    }
}
int find_parent(int p) {
    if(p == parent[p]) return p;
    else return parent[p] = find_parent(parent[p]);
}
void uni(int p, int q) {
    if (p > q) swap(p, q);
    p = find_parent(p);
    q = find_parent(q);
    if(q == p) return;
    parent[q] = p;
}
int main() 
{
    io;
    cin >> N >> M;
    init();
    int R;
    cin >> R;
    for(int i=0;i<R;i++) {
        cin >> known[i];
        if (i > 0) uni(known[i-1], known[i]);
    }
    for(int i=0;i<M;i++) {
        int loop; cin >> loop;
        bool check = false;
        int tmp = 0;
        while(loop--) {
            int people; cin >> people;
            v[i].push_back(people);
        }
        for(int j=1;j<v[i].size();j++) {
            uni(v[i][j], v[i][j-1]);
        }
    }

    int P = find_parent(known[0]);
    for(int i=0;i<M;i++) {
        bool check = false;
        for(auto it : v[i]) {
            if(find_parent(it) == P) {
                check = true;
                break;
            }
        }
        if(!check) ans++;
    }
    cout<<ans<<"\n";
    return 0;
}