#include <string>
#include <vector>
#include <set>
using namespace std;
set<int> s;
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int i=0;i<numbers.size();i++)
        for(int j=0;j<numbers.size();j++)
            if(i != j)
                s.insert(numbers[i] + numbers[j]);
    for(auto it : s)
        answer.push_back(it);
    return answer;
}