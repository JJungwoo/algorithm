/*
[boj] 2109. 순회강연
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, max_day, ans;
vector<pair<int, int> > cls;    // day, pay

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        int p, d;
        cin>>p>>d;
        cls.push_back(make_pair(d, p));
        if(max_day < d) max_day = d;
    }
    sort(cls.begin(), cls.end());
    int idx = 0;
    for(int i=1;i<max_day+1;i++){
        priority_queue<int> pq;
        while(idx < n && i >= cls[idx].first)
            pq.push(cls[idx++].second);
        
        if(!pq.empty()){
            ans += pq.top();
        }
    }
    cout<<ans<<"\n";
    return 0;
}