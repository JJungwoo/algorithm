/*
[boj] 2170. 선 긋기
https://www.acmicpc.net/problem/2170
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N;
vector<pair<int, int>> point;
int main() 
{
    io;
    cin >> N;
    while(N--) {
        int x, y;
        cin >> x >> y;
        point.push_back({x, y});
    }
    sort(point.begin(), point.end());
    int answer = 0;
    int left = point[0].first, right = point[0].second;
    for(int i=1;i<point.size();i++) {
        if (point[i].first >= right && point[i].second >= right) {
            answer += right - left;
            left = point[i].first;
            right = point[i].second;
        } else if (point[i].second >= right) {
            right = point[i].second;
        }
    }
    answer += right - left;
    cout << answer << "\n";
    return 0;
}
