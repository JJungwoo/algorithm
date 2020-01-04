/*
[BOJ] 16964. DFS 스페셜 저지
뭔 문제인가 싶다.. 똑같이 구현하고 출력 결과만 제대로 나오는지 확인하는건가? 일단 DFS를 구현한다.
https://joonas.tistory.com/94
https://www.acmicpc.net/board/view/34455
*/
#include <iostream>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
vector<int> v[100001];
bool visited[100001];
vector<int> ans;
vector<int> check;

void dfs(int x){
    if(visited[x]) return;
    ans.push_back(x);
    visited[x] = true;
    for(int i=0;i<v[x].size();i++){
        int k = v[x][i];
        if(!visited[k]){
            dfs(k);
        }
    }
}

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x, y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    check.resize(n+1);
    for(int i=0;i<n;i++) cin>>check[i];
    dfs(1);
    for(int i=0;i<n;i++){
        cout<<check[i]<<" : "<<ans[i]<<"\n";
        if(check[i] != ans[i])
        {
            cout<<"0\n";
            return 0;
        }
    }
    cout<<"1\n";
    return 0;
}