/*
[boj] 10775. 공항
https://www.acmicpc.net/problem/10775
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int parent[100001];
void init(int n) {
    for(int i=0;i<=n;i++){
        parent[i] = i;
    }
}
int find(int p) {
    if(p == parent[p]) return p;
    else return parent[p] = find(parent[p]);
}
int main() 
{
    io;
    int G, P, ans = 0;
    bool check = true;
    cin >> G >> P;
    init(G);
    for(int i=0; i<P; i++) {
        int gate;
        cin >> gate;
        if(check){
            if(find(gate) == 0) {
                check = false;
                continue;
            }else{
                parent[find(gate)] = parent[gate]-1;
            }
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}

