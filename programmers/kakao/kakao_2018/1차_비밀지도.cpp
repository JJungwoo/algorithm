/*
[programmers] 2018 KAKAO BLIND RECRUITMENT 1차 비밀지도
https://programmers.co.kr/learn/courses/30/lessons/17681
*/
#include <bits/stdc++.h>
using namespace std;
inline char expression_cipher(char c) {
    return (c == '1' ? '#' : ' ');
}
string convert_binary_notation(int num, int size) {
    string ret = "";
    while (num > 0) {
        ret.push_back(expression_cipher('0' + num % 2));
        num /= 2;
    }
    while (size > ret.length()) {
        ret.push_back(expression_cipher('0'));
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i=0;i<arr1.size();i++) {
        answer.push_back(convert_binary_notation(arr1[i] | arr2[i], n));
    }
    return answer;
}
