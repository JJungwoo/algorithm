/*
[boj] 2230. 수 고르기
https://www.acmicpc.net/problem/2230
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;
ll N, M, answer = 2e18;
vector<ll> v;
int main() 
{
    io;
    cin >> N >> M;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int left = 0, right = 0;
    while(left < N && right < N) {
        ll diff = v[right] - v[left];
        if (diff < M) {
            right++;
        } else {
            answer = min(answer, diff);
            left++;
        }
    }
    cout<<answer<<"\n";
    return 0;
}