/*
[boj] 14002. 가장 긴 증가하는 부분 수열 4
https://www.acmicpc.net/problem/14002
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, idx;
vector<int> arr, lis;
vector<pair<int, int>> lis_pos;
int main() 
{
    io;
    cin >> N;
    arr.resize(N);
    for(int i=0;i<N;i++) {
        cin >> arr[i];
        if (i == 0 || lis.back() < arr[i]) {
            lis.push_back(arr[i]);
            lis_pos.push_back({idx++, arr[i]});
        } else {
            int pos = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
            lis[pos] = arr[i];
            lis_pos.push_back({pos, arr[i]});
        }
    }

    stack<int> answer;
    for(int i=lis_pos.size()-1;i>=0;i--) {
        if(idx-1 == lis_pos[i].first) {
            answer.push(lis_pos[i].second);
            idx--;
        }
    }

    cout<<answer.size()<<"\n";
    while(!answer.empty()) {
        cout<<answer.top()<<" ";
        answer.pop();
    }
    return 0;
}
