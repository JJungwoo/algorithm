/*
[programmers] 2020 카카오 공채. 보석 쇼핑
https://programmers.co.kr/learn/courses/30/lessons/67258
*/
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<string, int> m;
vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int cnt = 0, N = gems.size();
    for(int i=0;i<N;i++) {
        if(m.find(gems[i]) == m.end())
            m[gems[i]] = cnt++;
    }

    cnt = 0;
    vector<int> chk(m.size(), 0);
    int left = 0, right = 0, ans_left = 0, ans_right = 0, ans = 1e9;

    while(left<=right) {
        if(cnt == m.size()) {
            if(ans > right - left + 1) {
                ans_left = left;
                ans_right = right;
                ans = right - left + 1;
            }
            if(chk[m[gems[left]]] > 0) {
                chk[m[gems[left]]]--;
                if(chk[m[gems[left]]] == 0)
                    cnt--;
            }
            left++;
        } else if(right == N) {
            break;
        } else {
            if(chk[m[gems[right]]] == 0)
                cnt++;
            chk[m[gems[right]]]++;
            right++;
        }
    }

    answer.push_back(ans_left+1);
    answer.push_back(ans_right);
    return answer;
}
