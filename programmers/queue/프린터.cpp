#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> qp;
    for(int i=0;i<priorities.size();i++){
        qp.push({i, priorities[i]});
    }
    sort(priorities.begin(), priorities.end(), greater<int>());
    int idx = 0;
    while(!qp.empty()){
        int value = qp.front().second;
        cout<<qp.front().first<<" , "<<value<<", idx"<<idx<<"\n";
        if(value < priorities[idx]){
            pair<int, int> temp = qp.front();
            qp.pop();
            qp.push(temp);
        }
        else {
            answer++;
            if(location == qp.front().first){
                break;
            }
            idx++;
            qp.pop();
        }
    }

    return answer;
}

