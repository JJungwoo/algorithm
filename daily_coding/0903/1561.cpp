/*
[boj] 1561. 놀이 공원
https://www.acmicpc.net/problem/1561
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;
ll runtimes[10001];
ll solve(ll N, ll M) {
    ll lo = 0, hi = 2000000000000;
    while(lo <= hi) {
        ll mid = (lo + hi) >> 1;
        ll sum = M;
        for(int i=0;i<M;i++){
            sum += mid / runtimes[i];
        }
        if(sum >= N) {
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    return hi + 1;
}
int main()
{
    io;
    ll N, M;
    cin >> N >> M;
    if(N <= M) {
        cout << N << "\n";
        return 0;
    }
    for(int i=0;i<M;i++) {
        cin >> runtimes[i];
    }
    ll time = solve(N, M);
    ll ans = 0, cnt = M;
    for(int i=0;i<M;i++)
        cnt += (time - 1) / runtimes[i];
    
    for(int i=0;i<M;i++) {
        if(time % runtimes[i] == 0) cnt++;
        if(cnt == N) {
            cout << i + 1 << "\n";
            break;
        }
    }
    return 0;
}