#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
map<int, int> m;    // 입장, 퇴장
vector<int> v;
int solution(vector<vector<int>> routes) {
    int answer = 0, idx = 0;
    sort(routes.begin(), routes.end());
    v.push_back(routes[0][1]);
    for(int i=1;i<routes.size();i++){
        if(v[idx] > routes[i][1]){
            v[idx] = routes[i][1];
        }
        if(v[idx] < routes[i][0]) {
            v.push_back(routes[i][1]);
            idx++;
            answer++;
        }
    }
    return answer + 1;
}