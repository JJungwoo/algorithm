/*
[boj] 15971. 두 로봇 
https://www.acmicpc.net/problem/15971
두 로봇이 만나는 가장 짧은 경로를 찾은 다음 가장 높은 가중치 값을 빼주면 해결!
*/

#include <iostream>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, a, b, max_way;
vector<pair<int, int> > cave[100001];
vector<int> path;
bool visited[100001];
int dfs(int cur, int value){
    int res = 0;
    if(cur == b-1) {
        for(auto it : path){
            if(it > max_way) max_way = it;
        }
        return value;
    }

    for(auto it : cave[cur]){
        int next = it.first, nvalue = it.second;
        if(visited[next]) continue;
        visited[next] = true;
        path.push_back(nvalue);
        res += dfs(next, value + nvalue);
        path.pop_back();
        visited[next] = false;
    }
    return res;
}
int main()
{
    io;
    cin>>n>>a>>b;
    for(int i=0;i<n-1;i++){
        int src, dest, val;
        cin>>src>>dest>>val;
        cave[src-1].push_back(make_pair(dest-1, val));
        cave[dest-1].push_back(make_pair(src-1, val));
    }
    visited[a-1] = true;
    int ans = dfs(a-1,0);
    cout<<ans-max_way<<"\n";
    return 0;
}