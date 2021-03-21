/*
[boj] 2785. 체인
https://www.acmicpc.net/problem/2785
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N;
vector<int> chain;
int main() 
{
    io;
    cin >> N;
    chain.resize(N);
    for(int i=0;i<N;i++) {
        cin >> chain[i];
    }
    sort(begin(chain), end(chain));
    int ans = 0; 
    while(1) {
        if(chain.size() == 1) break;
        chain[chain.size() - 2] += chain[chain.size() - 1];
        chain.pop_back();
        chain[0]--;
        ans++;

        if(chain[0] == 0) {
            for(int i=0;i<chain.size() - 1;i++) 
                chain[i] = chain[i + 1];
            chain.pop_back();
        }
    }
    cout<<ans<<"\n";
    return 0;
}
