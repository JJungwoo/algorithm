/*
[programmers] 위클리 챌린지 6주차 복서 
https://programmers.co.kr/learn/courses/30/lessons/85002
*/
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int id;
    int weight;
    int win;
    double wrate;
};
bool cmp (const Node& a, const Node& b) {
    if (a.wrate == b.wrate) {
        if (a.win == b.win) {
            if (a.weight == b.weight) {
                return a.id < b.id;
            }
            return a.weight > b.weight;
        }   
        return a.win > b.win;
    }
    return a.wrate > b.wrate;
}
vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    vector<Node> v;
    for (int i=0;i<weights.size();i++) {
        int win = 0, total = 0;
        double wrate = 0.0;
        for (int j=0;j<head2head[i].size();j++) {
            if (head2head[i][j] == 'N') continue;
            if (head2head[i][j] == 'W') {
                if (weights[i] < weights[j]) {
                    win++;
                }
                wrate++;
            }
            total++;
        }
        v.push_back({i + 1, weights[i], win, wrate == 0 ? 0 : (wrate / total) * 100.0});
    }
    sort(v.begin(), v.end(), cmp);
    for (Node i : v) {
        answer.push_back(i.id);
    }
    return answer;
}
