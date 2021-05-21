/*
[programmers] 2018 KAKAO BLIND RECRUITMENT 3차 압축
https://programmers.co.kr/learn/courses/30/lessons/17684
*/
#include <bits/stdc++.h>
using namespace std;
int last_idx = 27;
map<string, int> idx_map =
{
    {"A", 1}, {"B", 2}, {"C", 3}, {"D", 4}, {"E", 5},
    {"F", 6}, {"G", 7}, {"H", 8}, {"I", 9}, {"J", 10},
    {"K", 11}, {"L", 12}, {"M", 13}, {"N", 14}, {"O", 15},
    {"P", 16}, {"Q", 17}, {"R", 18}, {"S", 19}, {"T", 20},
    {"U", 21}, {"V", 22}, {"W", 23}, {"X", 24}, {"Y", 25},
    {"Z", 26}
};
vector<int> solution(string msg) {
    vector<int> answer;
    for (int i=0;i<msg.length();i++) {
        int jump = 0;
        string find_str, insert_str = "";
        for (int j=1;j<msg.length() + 1;j++) {
            if (idx_map.count(msg.substr(i, j)) > 0) {
                find_str = msg.substr(i, j);
                jump = j - 1;
            } else {
                insert_str = msg.substr(i, j);
                break;
            }
        }
        if (insert_str.compare("")) {
            idx_map[insert_str] = last_idx++;
        }
        answer.push_back(idx_map[find_str]);
        if (i + jump >= msg.length()) {
            break;
        }
        i += jump;
    }
    return answer;
}
