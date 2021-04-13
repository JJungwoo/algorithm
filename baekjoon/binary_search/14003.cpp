/*
[boj] 
https://www.acmicpc.net/problem/
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N;
vector<long long> v, lis;
vector<pair<int, long long> > lis_pos_pair;
int main() 
{
    io;
    int idx = 0;
    cin >> N;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin >> v[i];
        if (i == 0 || lis.back() < v[i]) {
            lis.push_back(v[i]);
            lis_pos_pair.push_back({idx, v[i]});
            idx++;
        }
        else {
            int pos = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
            lis[pos] = v[i];
            lis_pos_pair.push_back({pos, v[i]});
        }
    }
    stack<long long> answer;
    for(int i=lis_pos_pair.size()-1;i>=0;i--) {
        if(idx - 1 == lis_pos_pair[i].first) {
            answer.push(lis_pos_pair[i].second);
            idx--;
        }
    }

    cout<<answer.size()<<"\n";
    while(!answer.empty()) {
        cout<<answer.top()<<" ";
        answer.pop();
    }
    cout<<"\n";

    return 0;
}