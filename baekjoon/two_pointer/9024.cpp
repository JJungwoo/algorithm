/*
[boj] 9024. 두 수의 합 
https://www.acmicpc.net/problem/9024
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int MAX_INT = 1e10;
int main() 
{
    io;
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i];
        }
        // k와 차이가 가장 가까운 key와 벡터 조합들을 담은 맵 
        unordered_map<int, vector<pair<int, int>>> map;
        sort(v.begin(), v.end());
        int lo = 0, hi = n-1;
        int mindiff = MAX_INT;
        while (lo < hi) {
            int diff = abs(k - (v[hi] + v[lo]));
            if (diff <= mindiff) {
                mindiff = diff;
                map[mindiff].push_back({v[lo], v[hi]});
            } 
            
            if (k < v[hi] + v[lo]) {
                hi--;
            } else {
                lo++;
            }
        }
        cout << map[mindiff].size() << "\n";
    }
    return 0;
}