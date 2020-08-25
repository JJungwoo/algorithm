/*
[boj] 1781. 컵라면 
https://www.acmicpc.net/problem/1781
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, a, b;
long long ans;
vector<pair<int, int> > vp;
int main() 
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        vp.push_back(make_pair(a, b));
    }
    sort(vp.begin(), vp.end());
    priority_queue<int> pq;
    for(auto it : vp) {
        cout<<it.first<<" "<<it.second<<"\n";
        pq.push(-it.second);
        if(pq.size() > it.first) {
            pq.pop();
        }
    }
    while(!pq.empty()){
        cout<<pq.top()<<" , "<<ans<<"\n";
        ans += pq.top();
        pq.pop();
    }
    cout<<-ans<<"\n";
    return 0;
}

