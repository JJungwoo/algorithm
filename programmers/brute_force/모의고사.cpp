#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int peoples[3][10]={
    {1,2,3,4,5,1,2,3,4,5},
    {2,1,2,3,2,4,2,5},
    {3,3,1,1,2,2,4,4,5,5}
};
vector<pair<int, int>> map;
bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int idx = 0;
    map.push_back(make_pair(0,1));
    map.push_back(make_pair(0,2));
    map.push_back(make_pair(0,3));
    for(auto it : answers){
        if(peoples[0][idx%10] == it) map[0].first++;
        if(peoples[1][idx%8] == it) map[1].first++;
        if(peoples[2][idx%10] == it) map[2].first++;
        ++idx;
    }
    sort(map.begin(), map.end(), cmp);
    int tmp_val = map.begin()->first;
    for(auto it : map){
        if(tmp_val == it.first) answer.push_back(it.second);
    }
    return answer;
}
