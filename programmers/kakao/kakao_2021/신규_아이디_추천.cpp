/*
[programmers] 2021 KAKAO BLIND RECRUITMENT 신규 아이디 추천
https://programmers.co.kr/learn/courses/30/lessons/72410#
*/

#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string tmp = "";
    for(int i=0;i<new_id.length();i++) {
        char c = new_id[i];
        if(tmp.back() == '.' && new_id[i] == '.') continue;
        else if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9' 
           || c == '-' || c == '_' || c == '.') {
            if (c >= 'A' && c <= 'Z') tmp += (c - 'A') + 'a';
            else tmp += c;
        }
    }
    while(tmp.length() > 0 && tmp.back() == '.') tmp.pop_back();
    while(tmp.length() > 0 && tmp[0] == '.') tmp.erase(0, 1);
    if(tmp.length() == 0) tmp = 'a';
    if(tmp.length() >= 16) {
        answer = tmp.substr(0, 15);
        while(answer.length() > 0 && answer.back() == '.') answer.pop_back();
    }else{
        answer = tmp;
    }
    while(answer.length() < 3) 
        answer += answer.back();
    return answer;
}