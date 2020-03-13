/*
[boj] 15685. 드래곤 커브
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int n, m, ans;
bool visited[201][201], check[201][201];
vector<int> select_list;

void solve(int cnt){
    if(cnt > 3) return;
    if(cnt == 3){
        int size = select_list.size();
        for(int i=0;i<size;i++){
            if(check)
        }
        ans++;
        return ;
    }

    for(int i=0;i<n;i++){
        if(visited[i]) continue;
        visited[i] = true;
        select_list.push_back(i);
        solve(cnt+1);
        select_list.pop_back();
        visited[i] = false;
    }
}

int main()
{
    io;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        check[a][b] = true;
        check[b][a] = true;
    }
    solve(0);
    cout<<ans<<"\n";

    return 0;
}