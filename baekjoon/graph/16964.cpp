/*
[boj] 16964. DFS 스페셜 저지
https://www.acmicpc.net/problem/16964
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define ROOT 1
#define MAX_SIZE 100000 + 1
int N, orderIdx;
vector<int> tree[MAX_SIZE], order, dfsOrder;
bool visited[MAX_SIZE];
bool cmp(int a, int b) {
    return dfsOrder[a] < dfsOrder[b];
}
void dfs(int idx) {
    if (order[orderIdx++] != idx) {
        cout <<"0\n";
        exit(0);
    }
    
    for(int nxt : tree[idx]) {
        if (visited[nxt]) continue;
        visited[nxt] = true;
        dfs(nxt);
    }
}
int main() 
{
    io;
    cin >> N;
    for(int i=0;i<N-1;i++) {
        int A, B;
        cin >> A >> B;
        tree[A].push_back(B);
        tree[B].push_back(A);
    }
    order.resize(N+1);
    dfsOrder.resize(N+1);
    for(int i=0;i<N;i++) {
        cin >> order[i];
        dfsOrder[order[i]] = i + 1;
    }
    for(int i=1;i<=N;i++) {
        sort(tree[i].begin(), tree[i].end(), cmp);
    }
    visited[ROOT] = true;
    dfs(ROOT);

    cout<<"1\n";
    return 0;
}