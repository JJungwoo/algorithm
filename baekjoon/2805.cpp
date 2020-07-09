/*
[boj] 2085. 나무 자르기
https://www.acmicpc.net/problem/2085
*/

#include <iostream>
#include <vector>
#include <cmath>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;
ll n, m, ans;
vector<ll> wood;
ll check(ll value){
    ll res = 0;
    for(int i=0;i<n;i++){
        if(wood[i] - value > 0)
            res += wood[i] - value;
    }
    return res;
}
void solve(){
    ll lo = 0, hi = 10000000000001;
    while(lo < hi){
        ll mid = (lo + hi)/2;
        //cout<<mid<<","<<lo<<","<<hi<<"\n";
        if(check(mid) < m){
            hi = mid;
        }else {
            lo = mid + 1;
        }
    }
    ans = hi - 1;
}
int main()
{
    io;
    cin>>n>>m;
    wood.resize(n+1);
    for(int i=0;i<n;i++)
        cin>>wood[i];
    
    solve();
    cout<<ans<<"\n";
    return 0;
}