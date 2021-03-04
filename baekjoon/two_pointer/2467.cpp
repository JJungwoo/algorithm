/*
[boj] 2467. 용액
https://www.acmicpc.net/problem/2467
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;
const int MAX_INT = 1e10;
int N;
vector<ll> v;
int main()
{
    io;
    cin >> N;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin >> v[i];
    }
    int left = 0, right = N-1, ans_left, ans_right;
    ll min_diff = MAX_INT;
    while(left < right) {
        ll sum = v[right] + v[left];
        if(llabs(sum) < min_diff) {
            min_diff = llabs(sum);
            ans_left = left;
            ans_right = right;
        }
        if(sum > 0)
            right--;
        else
            left++;
    }
    cout<<v[ans_left]<<" "<<v[ans_right]<<"\n";
    return 0;
}