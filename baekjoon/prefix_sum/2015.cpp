/*
[boj] 2015. 수들의 합4
https://www.acmicpc.net/problem/2015
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long long N, K, answer;
vector<long long> v, psum;
int main() 
{
    io;
    cin >> N >> K;
    v.resize(N);
    psum.resize(N);
    map<long long, long long> m;
    for(int i=0;i<N;i++) {
        cin >> v[i];
        if (i==0) psum[i] = v[i];
        else psum[i] = psum[i-1] + v[i];
    }

    for(int i=0;i<N;i++) {
        if (psum[i] == K) answer++;
        answer += m[psum[i] - K];
        m[psum[i]]++;
    }

    cout<<answer<<"\n";
    return 0;
}