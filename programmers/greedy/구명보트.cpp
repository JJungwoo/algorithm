#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    for(int i=people.size()-1, idx = 0; i >= idx; i--){
        if(people[i] + people[idx] <= limit)
            idx++;
        answer++;
    }
    return answer;
}

