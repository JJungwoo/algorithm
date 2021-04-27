/*
[boj] 2352. 반도체 설계
https://www.acmicpc.net/problem/2352
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N;
vector<int> v, lis;
int main() 
{
    io;
    cin >> N;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin >> v[i];
    }

    for(auto it : v) {
        if (lis.size() == 0 || lis.back() < it) {
            lis.push_back(it);
        } else {
            int pos = lower_bound(lis.begin(), lis.end(), it) - lis.begin();
            lis[pos] = it;
        }
    }

    cout<<lis.size()<<"\n";
    return 0;
}