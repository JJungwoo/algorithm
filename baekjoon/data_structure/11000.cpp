/*
[boj] 11000. 강의실 배정
https://www.acmicpc.net/problem/11000
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N;
vector<pair<int,int>> vp;
priority_queue<int> pq;
bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
int main()
{
    io;
    cin >> N;
    while(N--) {
        int S, V;
        cin >> S >> V;
        vp.push_back({S, V});
    }
    sort(vp.begin(), vp.end(), cmp);
    
    pq.push(0);
    for(auto it : vp) {
        int cur = -pq.top();
        if (cur <= it.first)
            pq.pop();
        pq.push(-it.second);
    }
    cout<<pq.size()<<"\n";
    return 0;
}