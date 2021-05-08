/*
[boj] 3273. 두 수의 합
https://www.acmicpc.net/problem/3273
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, x, answer;
vector<int> v;
int main() 
{
    io;
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
    }
    cin >> x;
    sort(v.begin(), v.end());
    int left = 0, right = v.size() - 1;
    while (left < right) {
        int val = v[left] + v[right];
        if (val == x) {
            answer++;
        }
        if (val > x) {
            right--;
        } else {
            left++;
        }
    }
    cout << answer << "\n";
    return 0;
}
