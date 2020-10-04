/*
[boj] 1991. 트리 순회 
https://www.acmicpc.net/problem/1991
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
pair<int, int> tree[26];
void preorder(int idx, int N) {
    if (idx >= N)
        return ;

    cout << (char)(idx + 'A');
    if(tree[idx].first > 0)
        preorder(tree[idx].first, N);
    if(tree[idx].second > 0)
        preorder(tree[idx].second, N);
}
void inorder(int idx, int N) {
    if (idx >= N)
        return ;

    if(tree[idx].first > 0)
        inorder(tree[idx].first, N);
    cout << (char)(idx + 'A');
    if(tree[idx].second > 0)
        inorder(tree[idx].second, N);
}
void postorder(int idx, int N) {
    if (idx >= N)
        return ;

    if(tree[idx].first > 0)
        postorder(tree[idx].first, N);
    if(tree[idx].second > 0)
        postorder(tree[idx].second, N);
    cout << (char)(idx + 'A');
}
int main() 
{
    io;
    int N;
    cin >> N;
    for(int i=0;i<N;i++) {
        char R, LC, RC;
        cin >> R >> LC >> RC;
        tree[R-'A'] = make_pair(LC-'A', RC-'A');
    }

    preorder(0, N);
    cout<<"\n";
    inorder(0, N);
    cout<<"\n";
    postorder(0, N);
    cout<<"\n";
    return 0;
}