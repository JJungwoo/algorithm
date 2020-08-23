/*
[LeetCode] 386. Lexicographical Numbers
https://leetcode.com/problems/lexicographical-numbers/
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

class Solution {
public:
    map<string, int> m;
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1;i<=n;i++) {
            m.insert(make_pair(to_string(i), i));
        }
        for(auto it : m){
            ans.push_back(it.second);
        }
        return ans;
    }
};

int main()
{
    io;
    int n;
    cin>>n;
    Solution solution = Solution();
    vector<int> result = solution.lexicalOrder(n);

    return 0;
}
