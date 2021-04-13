/*
[programmers] 2020 KAKAO INTERSHIP 수식 최대화
https://programmers.co.kr/learn/courses/30/lessons/67257
*/
#include <bits/stdc++.h>
using namespace std;
vector<char> op;
vector<long long> nums;
void parser(string str) {
    string number = "";
    for(auto it : str) {
        if (it != '+' && it != '-' && it != '*') {
            number += it;
        } else {
            op.push_back(it);
            nums.push_back(stoll(number));
            number = "";
        }
    }
    nums.push_back(stoll(number));
}
static inline long long cal(long long a, long long b, char c) {
   switch(c) {
       case '*': return a * b;
       case '+': return a + b;
       case '-': return a - b;
   }
}
long long solution(string expression) {
    long long answer = 0;
    cout<<expression<<"\n";
    parser(expression);
    vector<char> v = {'*', '+', '-'};
    do{
        vector<long long> tmp_nums = nums;
        vector<char> tmp_op = op;
        for(auto it : v) {
            for(int i=0;i<tmp_op.size();i++) {
                if (it == tmp_op[i]) {
                    tmp_nums[i] = cal(tmp_nums[i], tmp_nums[i+1], tmp_op[i]);
                    tmp_nums.erase(tmp_nums.begin()+i+1);
                    tmp_op.erase(tmp_op.begin()+i);
                    i--;
                }
            }
        }
        answer = max(answer, abs(tmp_nums.front()));
    } while (next_permutation(v.begin(), v.end()));

    return answer;
}
