/*
[boj] 1414. 불우이웃돕기
https://www.acmicpc.net/problem/1414
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, total, parent[101];
struct obj{
    int x, y, val;
};
vector<obj> v;
inline int char_to_int(char c) {
    if('A' <= c && 'Z' >= c) return (int)(c-'A') + 27;
    return (int)(c-'a')+1;
}
bool cmp(obj a, obj b) {
    return a.val < b.val;
}
int find(int p) {
    if(p == parent[p]) return p;
    return parent[p] = find(parent[p]);
}
void uni(int p, int q) {
    p = find(p);
    q = find(q);
    if(p == q) return;
    if(p < q) parent[q] = p;
    else parent[p] = q;
}
int main()
{
    io;
    cin >> N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            char len;
            cin >> len;
            if(len == '0') continue; 
            if(i != j) 
                v.push_back({i, j, char_to_int(len)});
            total += char_to_int(len);
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0;i<N;i++) parent[i] = i;

    int minpath = 0, cnt = 1;
    for(auto it : v) {
        if(find(it.x) != find(it.y)) {
            uni(it.x, it.y);
            minpath += it.val;
            cnt++;
        } 
    }
    if (N == cnt) cout<<(total - minpath)<<"\n";
    else cout<<"-1\n";
    return 0;
}