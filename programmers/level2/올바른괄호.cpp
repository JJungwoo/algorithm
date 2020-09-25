/*
[programmers] 올바른 괄호
https://programmers.co.kr/learn/courses/30/lessons/12909
*/
#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int open = 0, close = 0;
    for(auto i : s) {
        if(i == '(') open++;
        else if(i == ')') close++;
        if(open < close) {
            answer = false;
            break;
        }
    }
    if(open != close) 
        answer = false;
    return answer;
}