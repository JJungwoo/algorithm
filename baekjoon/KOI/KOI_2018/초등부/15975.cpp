/*
[boj] 15975. 화살표 그리기
https://www.acmicpc.net/problem/15975
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;
vector<ll> v[100001];
ll n, ans;
int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(v[i].size() < 2) continue;
        sort(v[i].begin(), v[i].end());
        for(int j=0;j<v[i].size();j++){
            if(j == 0)
                ans += v[i][j+1] - v[i][j];
            else if(j == v[i].size()-1)
                ans += v[i][j] - v[i][j-1];
            else ans += min(v[i][j+1] - v[i][j], v[i][j] - v[i][j-1]);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
