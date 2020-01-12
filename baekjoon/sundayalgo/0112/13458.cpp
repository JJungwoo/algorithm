/*
[BOJ] 13458. 시험 감독
*/
#include <iostream>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

typedef long long ll;
const int MAX = 1e6;
ll n, b, c, ans;
ll room[MAX+1];

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>room[i];
    }
    cin>>b>>c;
    for(int i=0;i<n;i++){
        ll val = room[i] - b;
        ans++;
        if(val < 0) continue;
        ans += val / c;
        if(val%c != 0) ans++;
    }
    cout<<ans<<"\n";

    return 0;
}