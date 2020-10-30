/*
[boj] 1854. K번째 최단경로 찾기 
https://www.acmicpc.net/problem/1854
ref : https://dyndy.tistory.com/230
*/

#include <iostream>
#include <vector>
#include <queue>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, m, k, a, b, c;
vector<pair<int, int> > vp[1001];
priority_queue<int> path[1001];
struct comp{
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int> >, comp > pq;
int main() 
{
    io;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        vp[a-1].push_back(make_pair(b-1, c));
    }

    pq.push(make_pair(0, 0));
    path[0].push(0);
    
    while(!pq.empty()) {
        int cur = pq.top().first;
        int cost = pq.top().second;
        pq.pop();

        for(auto next : vp[cur]) {
            if(path[next.first].size() < k) {
                path[next.first].push(cost + next.second);
            } 
            else if(path[next.first].top() > cost + next.second) {
                path[next.first].pop();
                path[next.first].push(cost + next.second);
            }
            else
                continue;

            pq.push(make_pair(next.first, cost + next.second));
        }
    }
    
    for(int i=0;i<n;i++){
        if(path[i].size() == k) cout<<path[i].top()<<"\n";
        else cout<<"-1\n";
    }

    return 0;
}

