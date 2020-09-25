/*
[programmers] 카펫
https://programmers.co.kr/learn/courses/30/lessons/42842
*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;
    for(int i=1;i<=sum;i++) {
        if(sum % i == 0 && (sum / i) <= i && yellow == (i-2) * (sum/i-2)) {
            answer.push_back(i);
            answer.push_back(sum/i);
            break;
        }
    }
    return answer;  // 가로, 세로
}