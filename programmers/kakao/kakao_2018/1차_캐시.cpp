/*
[programmers] 2018 KAKAO BLIND RECRUITMENT 1차 캐시
https://programmers.co.kr/learn/courses/30/lessons/17680
*/
#include <bits/stdc++.h>
#define HIT 1
#define MISS 5
using namespace std;
void update_data(list<string> &list, string data) {
    auto cur = list.begin();
    bool find = false;
    while (cur != list.end()) {
        if (!data.compare(*cur)) {
            find = true;
            break;
        }
        cur++;
    }
    if (find) {
        list.erase(cur);
        list.push_back(data);
    } else {
        list.push_back(data);
    }
}
static inline string str_toupper(string str) {
    string ret = "";
    for(auto it : str) {
        ret += toupper(it);
    }
    return ret;
}
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> list;
    set<string> s;
    if(cacheSize == 0) return cities.size() * MISS;
    for(string it : cities) {
        string str = str_toupper(it);
        if (s.find(str) != s.end()) {
            update_data(list, str);
            answer += HIT;
        } else if (s.size() < cacheSize) {
            list.push_back(str);
            s.insert(str);
            answer += MISS;
        } else {
            s.erase(list.front());
            list.pop_front();
            list.push_back(str);
            s.insert(str);
            answer += MISS;
        }
    }
    return answer;
}
