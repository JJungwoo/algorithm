/*
[programmers] 2021 KAKAO BLIND RECRUITMENT 메뉴 리뉴얼
https://programmers.co.kr/learn/courses/30/lessons/72411
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
unordered_map<string, int> msi;
int course_cnt[11];
bool visited[21];
vector<string> course_list[11][21];
void combi(string s, int idx, string res) {
    if(res.length() >= 1) {
        msi[res]++;
        course_cnt[res.length()] = max(course_cnt[res.length()], msi[res]);
        course_list[res.length()][msi[res]].push_back(res);
    }

    for(int i=idx;i<s.length();i++) {
        if(visited[i]) continue;
        visited[i] = true;
        combi(s, i, res + s[i]);
        visited[i] = false;
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(string& s:orders){
        sort(s.begin(),s.end());
        combi(s, 0, "");
    }

    for(int i : course) {
        if(course_cnt[i] > 1) {
            for(string s : course_list[i][course_cnt[i]])
                answer.push_back(s);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
