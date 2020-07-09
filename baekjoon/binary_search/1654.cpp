/*
[boj] 1654. 랜선 자르기
https://www.acmicpc.net/problem/1654
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;
ll k, n, ans, max_cable, total;
ll cable[10001];
ll check(ll value){
    int sum = 0;
    for(int i=0;i<k;i++){
        sum += cable[i] / value;
    }
    return sum;
}
void solve(){
    //ll left = 1, right = 2147483647;
    ll left = 0, right = 10000000000001;
    while(left < right){
        ll mid = (left + right)/2;
        ll res = check(mid);
        if(res < n){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    ans = right - 1;
}

int main()
{
    io;
    cin>>k>>n;
    for(int i=0;i<k;i++){
        cin>>cable[i];
    }
    solve();
    cout<<ans<<"\n";
    return 0;
}