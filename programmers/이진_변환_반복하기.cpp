/*
[programmers] 월간 코드 챌린지 시즌1 이진 변환 반복하기
https://programmers.co.kr/learn/courses/30/lessons/70129
*/
#include <bits/stdc++.h>
using namespace std;
static inline pair<string, int> remove_zero(string s) {
    string ret = "";
    for (auto it : s)
        if (it == '1')
            ret.push_back(it);
    return {ret, s.length() - ret.length()};
}
static inline string convert_binary_notation(int len) {
    string ret = "";
    while (len / 2 > 0) {
        ret.push_back((len % 2) + '0');
        len /= 2;
    }
    ret.push_back((len % 2) + '0');
    reverse(ret.begin(), ret.end());
    return ret;
}
vector<int> solution(string s) {
    vector<int> answer(2, 0);
    int loop = 0;
    while (s.length() > 1) {
        auto res = remove_zero(s);
        answer[1] += res.second;
        loop++;
        s = convert_binary_notation(res.first.length());
    }
    answer[0] = loop;
    return answer;
}
