#include <string>
#include <vector>
#include <queue>
using namespace std;
queue<pair<int, int>> bridge;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1, cur_weight = truck_weights[0], idx = 1;
    bridge.push(make_pair(truck_weights[0], 0));
    while(!bridge.empty()){
        pair<int, int> tmp = bridge.front();
        if(answer - tmp.second == bridge_length){
            cur_weight -= tmp.first;
            bridge.pop();
        }
        if(idx < truck_weights.size() && cur_weight + truck_weights[idx] <= weight){
            bridge.push(make_pair(truck_weights[idx], answer));
            cur_weight += truck_weights[idx++];
        }
        
        answer++;
    }
    return answer;
}
