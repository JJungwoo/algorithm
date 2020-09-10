/*
[programmers] 2018 KAKAO BLIND RECRUITMENT [1차] 뉴스 클러스터링
https://programmers.co.kr/learn/courses/30/lessons/17666
*/

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<string, int> m1, m2, uni, sum;
bool isAlphabet(char c) {
    if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') return true;
    return false;
}
bool isPossible(string &tmp) {
    if(isAlphabet(tmp[0]) && isAlphabet(tmp[1])) {
        tmp[0] = tmp[0] <= 'Z' ? tmp[0] + 32 : tmp[0];
        tmp[1] = tmp[1] <= 'Z' ? tmp[1] + 32 : tmp[1];
        return true;
    }
    return false;
}
void makeUni() {
    for(auto it : m1) {
        if(m2.find(it.first) != m2.end()) {
            uni[it.first] = min(m2.find(it.first)->second, it.second);
        }
    }
}
void makeSum(unordered_map<string, int> a, unordered_map<string, int> &b) {
    for(auto it : a) {
        if(b.find(it.first) != b.end()) 
            b[it.first] = max(b.find(it.first)->second, it.second);
        else
            b[it.first] = it.second;
    }
}
int solution(string str1, string str2) {
    int answer = 0;
    
    for(int i=0;i<str1.length();i++){
        string element = str1.substr(i, 2);
        if(isPossible(element)) {
            m1[element]++;
        }
    }
    
    for(int i=0;i<str2.length();i++){
        string element = str2.substr(i, 2);
        if(isPossible(element)) {
            m2[element]++;
        }
    }
    makeUni();
    makeSum(m1, sum);
    makeSum(m2, sum);
    
    int usum = 0, ssum = 0;
    for(auto u : uni) 
        usum += u.second;
    for(auto s : sum)
        ssum += s.second;
    
    float result;
    if(!usum && !ssum)
        result = 1;
    else 
        result = (float)usum / ssum;
    
    answer = result * 65536;
    
    return answer;
}