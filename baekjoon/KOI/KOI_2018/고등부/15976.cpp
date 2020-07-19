/*
[boj] 15976. XCorr
https://www.acmicpc.net/problem/15976
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;
ll n,m,a,b,x,y,ans;
vector<pair<ll, ll> > xv, yv;
vector<ll> psum_v, pidx_v;
int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        xv.push_back(make_pair(x,y));
    }
    cin>>m;
    ll sum = 0;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        sum += y;
        pidx_v.push_back(x);
        psum_v.push_back(sum);
    }
    cin>>a>>b;

    for(auto it : xv){
        ll lidx = lower_bound(pidx_v.begin(), pidx_v.end(), it.first + a) - pidx_v.begin();
        ll ridx = lower_bound(pidx_v.begin(), pidx_v.end(), it.first + b) - pidx_v.begin();
        if(ridx == pidx_v.size() || pidx_v[ridx] > it.first + b) ridx--;
        if(ridx < lidx) continue;
        if(lidx == 0) ans += it.second * psum_v[ridx];
        else ans += it.second * (psum_v[ridx] - psum_v[lidx - 1]);
    }
    cout<<ans<<"\n";
    return 0;
}
/*
typedef long long ll;
ll n,m,a,b,x,y,ans;
map<ll, ll> xmap, ymap;
int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        xmap.insert(make_pair(x,y));
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        ymap.insert(make_pair(x,y));
    }
    cin>>a>>b;

    for(auto it : xmap){
        for(int i=a;i<=b;i++){
            //cout<<it.first<<" - "<<i<<" = "<<
            if(ymap.find(it.first+i) != ymap.end()){
                //cout<<ymap.find(it.first+i)->second<<" , "<<it.second<<"\n";
                ans += ymap.find(it.first+i)->second * it.second;
            }
        }
    }
    cout<<ans<<"\n";
    
    return 0;
}
*/