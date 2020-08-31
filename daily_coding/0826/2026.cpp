/*
[boj] 2026. 소풍 
https://www.acmicpc.net/problem/2026
*/

#include <iostream>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int relation[901][901];
bool visited[901], ans;
void dfs(int idx, int N, int K, vector<int> &tmp) {
    tmp.push_back(idx);
    if(tmp.size() == K) {
        for(int i : tmp){
            cout<<i<<"\n";
        }
        ans = true;
        return ;
    }

    for(int i=idx+1;i<=N;i++) {
        bool flag = true;
        if(relation[idx][i]) {
            for(int j : tmp) {
                if(!relation[j][i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) 
                dfs(i, N, K, tmp);
        } 
    }
}
int main() 
{
    io;
    int N, K, F;
    cin >> K >> N >> F;
    vector<int> student(N+1);
    for(int i=0; i<F; i++) {
        int A, B;
        cin >> A >> B;
        relation[A][B] = relation[B][A] = 1;
    }

    for(int i=1;i<=N;i++) {
        vector<int> V;
        dfs(i, N, K, V);
        if(ans) 
            break;
    }
    if(!ans)
        cout<<"-1\n";
    
    return 0;
}

