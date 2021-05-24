/*
[programmers] 월간 코드 챌린지 시즌1 쿼드압축 후 개수 세기
https://programmers.co.kr/learn/courses/30/lessons/68936
*/
#include <bits/stdc++.h>
using namespace std;
int ans[2];
static inline void do_compact_array(int x, int y, vector<vector<int>> &arr, int size) {
    if (size == 1) {
        ans[arr[x][y]]++;
        return;
    }
    bool ispossible = true;
    int stand = arr[x][y];
    for (int i=x;i<x+size;i++) {
        for (int j=y;j<y+size;j++) {
            if (stand != arr[i][j]) {
                ispossible = false;
                break;
            }
        }
    }
    if (ispossible) {
        ans[stand]++;
    } else {
        do_compact_array(x, y, arr, size / 2);
        do_compact_array(x + size / 2, y, arr, size / 2);
        do_compact_array(x, y + size / 2, arr, size / 2);
        do_compact_array(x + size / 2, y + size / 2, arr, size / 2);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    do_compact_array(0, 0, arr, arr.size());
    answer.push_back(ans[0]);
    answer.push_back(ans[1]);
    return answer;
}
