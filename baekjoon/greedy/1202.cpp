/*
[boj] 1202. 보석 도둑 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, k;
long long ans;
vector<pair<int, int> > jewel;
vector<int> bag;
int main()
{
    io;
    cin>>n;
    cin>>k;
    for(int i=0;i<n;i++){
        int m, v;
        cin>>m>>v;
        jewel.push_back(make_pair(m,v));   
    }
    for(int i=0;i<k;i++){
        int c; cin>>c;
        bag.push_back(c);
    }
    sort(jewel.begin(), jewel.end());
    sort(bag.begin(), bag.end());
    
    int idx = 0;
    priority_queue<int> pq;
    for(auto it : bag){

        while(idx < n && it >= jewel[idx].first)
            pq.push(jewel[idx++].second);

        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }

    }
    cout<<ans<<"\n";
    return 0;
}