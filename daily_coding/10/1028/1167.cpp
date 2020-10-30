/*
[boj] 1167. 트리의 지름 
https://www.acmicpc.net/problem/1167
*/

#include <iostream>
#include <cstring>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, dp[100001], answer;
vector<pair<int, int> > vp[100001];
bool visited[100001];
void dfs(int idx) {
    visited[idx] = true;
    for(auto next : vp[idx]) {
        if(dp[next.first] < dp[idx] + next.second && !visited[next.first]) {
            dp[next.first] = dp[idx] + next.second;
            dfs(next.first);
        }
    }
}
void find(int idx, int value) {
    answer = max(answer, value);
    visited[idx] = true;
    for(auto next : vp[idx]) {
        if(!visited[next.first]) {
            find(next.first, value + next.second);
        }
    }
}
int main() 
{
    io;
    cin >> N;
    for(int i=0;i<N;i++) {
        int value;
        cin >> value;
        int A = value;
        while(value != -1) {
            cin >> value;
            if(value == -1) break;
            int B = value;
            cin >> value;
            vp[A].push_back(make_pair(B, value));
        }
    }

    dfs(1);
    int maxval = 0, maxidx = 0;
    for(int i=1;i<=N;i++) {
        if(maxval < dp[i]) {
            maxval = dp[i];
            maxidx = i;
        }
    }
    memset(visited, 0, sizeof(visited));
    find(maxidx, 0);
    cout<<answer<<"\n";
    return 0;
}