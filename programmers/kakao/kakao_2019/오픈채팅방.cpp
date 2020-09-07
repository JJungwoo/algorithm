/*
[programmers] 2019 KAKAO BLIND RECRUITMENT 오픈채팅방
https://programmers.co.kr/learn/courses/30/lessons/42888
*/

#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
map<string, string> m;
vector<string> parseCmd(string cmd) {
    string input = "";
    vector<string> result;
    for(auto c : cmd) {
        if(c == ' ') {
            result.push_back(input);
            input = "";
        }
        else input += c;
    }
    result.push_back(input);
    return result;
}
vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<string, string>> output;
    for(int i=0;i<record.size();i++) {
        vector<string> cmd = parseCmd(record[i]);
        if(!cmd[0].compare("Enter")){
            if(m.find(cmd[1]) == m.end())
                m.insert({cmd[1], cmd[2]});
            else 
                m.find(cmd[1])->second = cmd[2];
            output.push_back({cmd[1], "님이 들어왔습니다."});
        }else if(!cmd[0].compare("Leave")){
            output.push_back({cmd[1], "님이 나갔습니다."});
        }else if(!cmd[0].compare("Change")) {
            m.find(cmd[1])->second = cmd[2];
        }
    }
    for(auto it : output) {
        answer.push_back("" + m.find(it.first)->second + it.second);
    }
    return answer;
}