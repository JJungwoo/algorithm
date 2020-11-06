#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
unordered_map<string, int> m;
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for(int i=0;i<participant.size();i++) {
        m[participant[i]]++;
    }
    for(int i=0;i<completion.size();i++) {
        if(m[completion[i]] > 0) {
            m[completion[i]]--;
            if(m[completion[i]] == 0) 
                m.erase(completion[i]);
        }
    }
    answer = m.begin()->first;
    return answer;
}