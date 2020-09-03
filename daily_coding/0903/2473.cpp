/*
[boj] 2473. 세 용액 
https://www.acmicpc.net/problem/2473
ref : https://travelbeeee.tistory.com/246
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;
const ll INF = 1e10;
vector<ll> v;
int main() 
{
    io;
    int N;
    cin >> N;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin >> v[i];
    }
    ll ans = INF, ans1, ans2, ans3;
    sort(v.begin(), v.end());
    for(int i=0;i<N;i++) {
        bool end = false;
        int lo = i + 1, hi = N - 1;
        while(lo < hi) {
            ll sum = v[i] + v[lo] + v[hi];
            if(abs(ans) > abs(sum)) {
                ans = sum;
                ans1 = v[i], ans2 = v[lo], ans3 = v[hi];
            }
            if(sum == 0) {
                end = true;
                break;
            }else if(sum > 0) {
                hi--;
            }else {
                lo++;
            }
        }
        if(end) break;
    }
    cout << ans1 << " " << ans2 << " " << ans3 << "\n";
    return 0;
}