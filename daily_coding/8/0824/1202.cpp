/*
[boj] 1202. 보석 도둑 
https://www.acmicpc.net/problem/1202
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
vector<pair<int, int> > jewel;
vector<int> bag;
long long ans;
bool cmp(const pair<int, int> a, const pair<int, int> b) {
    if(a.first == b.first) 
        return a.second > b.second;
    return a.first < b.first;
}
int main() 
{
    io;
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int M, V;
        cin >> M >> V;
        jewel.push_back(make_pair(M, V));
    }
    for(int i = 0; i < K; i++) {
        int C;
        cin >> C;
        bag.push_back(C);
    }
    sort(jewel.begin(), jewel.end(), cmp);
    sort(bag.begin(), bag.end());

    priority_queue<int> pq;
    int idx = 0;
    for(int weight : bag) {
        while(idx < jewel.size() && jewel[idx].first <= weight) {
            pq.push(jewel[idx].second);
            idx++;
        }
        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }
    cout<<ans<<"\n";
    return 0;
}