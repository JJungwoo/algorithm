/*
[programmers] 징검다리
https://programmers.co.kr/learn/courses/30/lessons/43236
*/
#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> &rocks, int mid, int n) {
    int pos = 0, cnt = 0;
    for (int i=0;i<rocks.size();i++) {
        if (rocks[i] - pos < mid) {
            cnt++;
            if (cnt > n) {
                return false;
            }
        }
        else 
            pos = rocks[i];
    }
    return true;
}
int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int lo = 1, hi = distance;
    sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(rocks, mid, n)) {
            lo = mid + 1;
            answer = max(answer, mid);
        } else {
            hi = mid - 1;
        }
    }
    return answer;
}
