#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, int> m;
    for(int i=0;i<skill.length();i++)
        m.insert(make_pair(skill[i], i));

    for(auto it : skill_trees){
        int seq = 0;
        bool check = true;
        for(int i=0;i<it.length();i++){
            auto tmp = m.find(it[i]);
            if(tmp != m.end()){
                if(tmp->second != seq) {
                    check = false;
                    break;
                }
                seq++;
            }
        }
        if(check) answer++;
    }

    return answer;
}
