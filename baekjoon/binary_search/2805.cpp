/*
[boj] 2805. 나무 자르기
https://www.acmicpc.net/problem/2805
*/

#include <iostream>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;
int N, M;
vector<ll> woods;
bool isSuccess(ll mid) {
    ll sum = 0;
    for(auto it : woods) {
        if (it >= mid) {
            sum += it - mid;
        }
    }
    return (sum >= M);
}
int main() 
{
    io;
    cin >> N >> M;
    ll maxw = 0;
    woods.resize(N+1);
    for(int i=0;i<N;i++) {
        cin >> woods[i];
        if(maxw < woods[i]) maxw = woods[i];
    }
    ll lo = 0, hi = maxw;
    while(lo <= hi) {
        ll mid = (lo + hi) / 2;
        if(isSuccess(mid)) {
            lo = mid + 1;
        }else {
            hi = mid - 1;
        }
    }
    cout<<lo - 1<<"\n";
    return 0;
}