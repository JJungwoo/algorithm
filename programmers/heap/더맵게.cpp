#include <string>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int> pq;
int solution(vector<int> scoville, int K) {
    int answer = 0, chk = 0;
    for(auto it : scoville)
        pq.push(-it);

    while(!pq.empty()){
        int cur = -pq.top();
        if(cur > K) break;
        if(pq.size() == 1) return -1;
        if(!pq.empty()) pq.pop();
        int mix = cur + (-pq.top()) * 2;
        if(!pq.empty()) pq.pop();
        pq.push(-mix);
        answer++;
    }
    return answer;
}
