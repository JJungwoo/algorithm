#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
unordered_map<string, int> m;
bool str_compare(string A, string B) {
    if(A.length() != B.length()) return false;
    for(int i=0;i<A.length();i++) {
        if(A[i] == '*') continue;
        else if(A[i] != B[i]) return false;
    }
    return true;
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 1;
    for(int i=0;i<user_id.size() - banned_id.size();i++) {
        string tmp = "";
        int cnt = 0;
        for(int z=0;z<banned_id.size();z++) {
            for(int j=i;j<user_id.size();j++) {
                if(str_compare(banned_id[z], user_id[j])) {
                    tmp += user_id[j] + " ";
                    cnt++;
                    break;
                }
            }
        }
        
        if(cnt == banned_id.size()) {
            if(m.find(tmp) == m.end())
                m.insert({tmp, 1});
            else m.find(tmp)->second++;
            cout<<tmp<<"\n";
        }
    }
    answer = m.size();
    return answer;
}