/*
[boj] 1725. 히스토그램
https://www.acmicpc.net/problem/1725
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;
const ll MAX_LL = 1e10;
int N;
ll ans;
vector<ll> v;
int main() 
{
    io;
    cin >> N;
    v.resize(N+1);
    for(int i=0;i<N;i++) {
        cin >> v[i];
    }
    v[N] = 0;
    stack<ll> s;
    for(int i=0;i<=N;i++) {
        ll min_heigth = MAX_LL;
        while(!s.empty() && v[s.top()] >= v[i]) {
            ll cur = s.top();
            s.pop();
            int w;
            if(s.empty()) w = i;
            else w = (i - s.top() - 1);
            ans = max(ans, v[cur] * w);
        }
        s.push(i);
    }
    cout<<ans<<"\n";
    return 0;
}
