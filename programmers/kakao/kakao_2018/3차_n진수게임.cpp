/*
[programmers] 2018 KAKAO BLIND RECRUITMENT [3차] n진수 게임
https://programmers.co.kr/learn/courses/30/lessons/17687
*/

#include <bits/stdc++.h>
using namespace std;
char nChar[16] =
{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
 'A', 'B', 'C', 'D', 'E', 'F'};
string convert(int n, int size, int seq, int t) {
    string ret = "";
    int curIdx = 0, value = 0;
    while (ret.length() < t) {
        int temp = value;
        string convertStr = "";
        do {
            convertStr += nChar[temp % n];
            temp /= n;
        } while(temp > 0);
        reverse(convertStr.begin(), convertStr.end());

        for(int i=0;i<convertStr.size();i++) {
            if (seq == curIdx) {
                ret += convertStr[i];
                if (ret.length() >= t) break;
            }
            curIdx = (curIdx + 1) % size;
        }
        value++;
    }
    return ret;
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    return answer = convert(n, m, p - 1, t);
}
