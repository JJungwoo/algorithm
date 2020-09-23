/*
[programmers] 주식가격
https://programmers.co.kr/learn/courses/30/lessons/42584
*/
#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
stack<pair<int, int> > st;
vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n, 0);
    for(int i=0;i<prices.size();i++) {
        while(!st.empty() && st.top().first > prices[i]) {
            answer[st.top().second-1] = i - st.top().second + 1;
            st.pop();
        }
        st.push({prices[i], i+1});
    }
    while(!st.empty()) {
        answer[st.top().second-1] = n - st.top().second;
        st.pop();
    }
    return answer;
}