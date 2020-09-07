/*
[programmers] 2019 KAKAO BLIND RECRUITMENT 실패율
https://programmers.co.kr/learn/courses/30/lessons/42889
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
map<int, int> m;
bool cmp(const pair<float, int> A, const pair<float, int> B) {
    if(A.first == B.first) return A.second < B.second;
    return A.first > B.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<float, int>> frate;
    for(int i : stages){
        if(m.count(i) == 0) m.insert({i, 1});
        else m.find(i)->second++;
    }
    int total = stages.size();
    for(int i=1;i<=N;i++){
        if(m.find(i) == m.end()) {
            frate.push_back({0, i});
        }else{
            int cnt = m.find(i)->second;
            frate.push_back({(float)cnt/total, i});
            total -= cnt;
        }
    }
    sort(frate.begin(), frate.end(), cmp);
    for(auto it : frate) {
        answer.push_back(it.second);
    }
    return answer;
}