/*
[programmers] 단어 변환
https://programmers.co.kr/learn/courses/30/lessons/43163
*/
#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> m;
int bfs(string begin, string target, vector<vector<string>> words_graph, vector<bool> visited) {
    queue<pair<string, int>> q;
    q.push({begin, 0});
    visited[m[begin]] = true;
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        if (!target.compare(cur.first)) {
            return cur.second;
        }
        for(auto it : words_graph[m[cur.first]]) {
            string next = it;
            if(visited[m[next]]) continue;
            visited[m[next]] = true;
            q.push({next, cur.second + 1});
        }
    }
    return 0;
}
bool inline check_words(string a, string b) {
    int diff_cnt = 0;
    for(int i=0;i<a.length();i++) {
        if (a[i] != b[i]) diff_cnt++;
    }
    return diff_cnt > 1 ? false : true;
}
vector<vector<string>> init_graph(vector<string> words) {
    vector<vector<string>> ret(words.size());
    for(int i=0;i<words.size();i++) {
        m[words[i]] = i;
        for(int j=0;j<words.size();j++) {
            if (i == j) continue;
            if (check_words(words[i], words[j])) {
                ret[i].push_back(words[j]);
            }
        }
    }
    return ret;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<bool> visited(words.size() + 1, false);
    m[begin] = words.size();
    words.push_back(begin);
    return answer = bfs(begin, target, init_graph(words), visited);
}
