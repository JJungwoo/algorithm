/*
[programmers] 2018 KAKAO BLIND RECRUITMENT [3차] 파일명 정렬
https://programmers.co.kr/learn/courses/30/lessons/17686
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
struct obj{
    string name;
    string head;
    string number;
};
bool cmp(const obj &A, const obj &B) {
    if (A.head == B.head) {
        return stoi(A.number) < stoi(B.number);
    } else {
        return A.head < B.head;
    }
}
obj command_parser(string &s) {
    string head, number;
    bool chk = false;
    int idx = 0;
    for(char c : s) {
        if(c >= '0' && c <= '9') {
            number += c;
            idx++;
            if(idx >= 5) break;
            chk = true;
        } else if(!chk) {
            head += tolower(c);
        } else break;
    }
    return {s, head, number};
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<obj> tmp;
    for(auto s : files) {
        tmp.push_back(command_parser(s));
    }
    stable_sort(begin(tmp), end(tmp), cmp);
    for(auto it : tmp) {
        answer.push_back(it.name);
    }
    return answer;
}
