/*
[programmers] 124 나라의 숫자
https://programmers.co.kr/learn/courses/30/lessons/12899
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string solution(int n) {
    string answer = "";
    
    if(n < 3)
        return to_string(n%3);
    
    while(n >= 1) {
        if(n%3 == 0) {
            answer += "4";
            n /= 3;
            n--;
        }else{
            answer += to_string(n%3);
            n /= 3;
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}