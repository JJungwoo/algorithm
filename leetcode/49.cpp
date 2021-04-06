/*
[LeetCode] 49. Group Anagrams
https://leetcode.com/problems/group-anagrams/
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        vector<map<char, int>> vmci;
        for(int i=0;i<strs.size();i++) {
            map<char, int> mci;
            for(char c : strs[i])
                mci[c]++;
            vmci.push_back(mci);
        }
        map<string, vector<string>> mss;
        for(int i=0;i<vmci.size();i++) {
            string str = "";
            for(auto it : vmci[i]) {
                int loop = it.second;
                while(loop--) {
                    str += it.first;
                }
            }
            mss[str].push_back(strs[i]);
        }
        for(auto it1 : mss) {
            answer.push_back(it1.second);
        }
        return answer;
    }
};
