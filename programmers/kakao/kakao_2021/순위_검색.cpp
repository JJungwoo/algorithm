/*
[programmers] 2021 KAKAO BLIND RECRUITMENT 순위 검색
https://programmers.co.kr/learn/courses/30/lessons/72412
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    map<string, vector<int>> m;
    for(auto it : info) {
        istringstream iss(it);
        string astr[5];
        iss >> astr[0] >> astr[1] >> astr[2] >> astr[3] >> astr[4];
        for (int i = 0; i < (1 << 4); i++) {
            string key;
            for (int j = 0; j < 4; j++) {
                if (i & (1 << j)) key += astr[j];
                else key += '-';
            }
            m[key].push_back(stoi(astr[4]));
        }
    }
    for(auto &it : m) {
        sort(it.second.begin(), it.second.end());
    }
    for(auto it : query) {
        istringstream iss(it);
        string astr[8], real_query = "";
        iss >> astr[0] >> astr[1] >> astr[2] >> astr[3] >> astr[4] >> astr[5] >> astr[6] >> astr[7];
        real_query = astr[0] + astr[2] + astr[4] + astr[6];
        auto v = m[real_query];
        answer.push_back(v.end() - lower_bound(v.begin(), v.end(), stoi(astr[7])));
    }
    return answer;
}
