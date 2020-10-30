/*
[boj] 10165. 버스 노선 
https://www.acmicpc.net/problem/10165
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
vector<pair<int, int> > vp;
int main() 
{
    io;
    int N, M;
    cin >> N >> M;
    for(int i=0;i<M;i++) {
        int A, B;
        cin >> A >> B;
        if(A < B)
            vp.push_back(make_pair(A, B));
        else 
            vp.push_back(make_pair(B, A));
    }
    sort(vp.begin(), vp.end());
    for(auto it : vp) {
        cout<<it.first<<","<<it.second<<"\n";
    }
    return 0;
}

