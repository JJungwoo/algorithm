/*
[programmers] 2020 카카오 공채. 괄호 변환
https://programmers.co.kr/learn/courses/30/lessons/60058#
*/
#include <string>
#include <vector>

using namespace std;
bool check_str(string p) {
    int open = 0;
    for(char c : p) {
        if(c == '(') open++;
        else open--;
        if(open < 0) {
            return false;
        }
    }
    return true;
}
string solve(string p) {
    if(p == "") return "";
    string u, v;
    int open = 0, close = 0;
    for(int i=0;i<p.length();i++) {
        if(p[i] == '(') open++;
        else close++;
        if(open == close) {
            u = p.substr(0, i+1);
            v = p.substr(i+1);
            break;
        }
    }
    if(check_str(u)) {
        return u + solve(v);
    } else {
        string tmp = '(' + solve(v) + ')';
        u = u.substr(1, u.length() - 2);
        for(int i=0;i<u.length();i++) {
            if(u[i] == '(') u[i] = ')';
            else u[i] = '(';
        }
        tmp += u;
        return tmp;
    }
}
string solution(string p) {
    string answer = "";
    return solve(p);
}
