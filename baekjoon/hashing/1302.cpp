/*
[boj] 1302. 베스트셀러
https://www.acmicpc.net/problem/1302
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
map<string, int> m;
int N;
bool cmp(pair<int, string> a, pair<int, string> b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
int main() 
{
    io;
    cin >> N;
    while(N--) {
        string input;
        cin >> input;
        m[input]++;
    }
    vector<pair<int, string>> v;
    for(auto it : m) {
        v.push_back({it.second, it.first});
    }
    sort(v.begin(), v.end(), cmp);
    cout<<v[0].second<<"\n";
    return 0;
}
