/*
[boj] 1068. 트리
https://www.acmicpc.net/problem/1068
*/

#include <iostream>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, root, removenode, answer;
vector<int> tree[52];
void dfs(int idx) {
    if(tree[idx].size() == 0)
        answer++;
    for(auto it : tree[idx])
        dfs(it);
}
void find_removenode(int idx) {
    for (auto it = tree[idx].begin(); it != tree[idx].end(); it++) {
        if (*it == removenode) {
            tree[idx].erase(it);
            return ;
        }
        find_removenode(*it);
    }
}
int main() 
{
    io;
    cin >> N;
    for(int i=0;i<N;i++) {
        int value; cin >> value;
        if(value == -1) root = i;
        else tree[value].push_back(i);
    }
    cin >> removenode;
    if(root != removenode) {
        find_removenode(root);
        dfs(root);
    }
    cout<<answer<<"\n";
    return 0;
}