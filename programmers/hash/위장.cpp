#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
map<string, int> m;
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    for(int i=0;i<clothes.size();i++){
        if(m.find(clothes[i][1]) == m.end()){
            m.insert(make_pair(clothes[i][1], 1));
        }else{
            m.find(clothes[i][1])->second++;
        }
    }
    
    for(auto it : m){
        answer *= (it.second + 1);
    }

    return answer - 1;
}
