#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
// 장르, 전체 재생 횟수
map<string, int> msi, seq;
// 재생 횟수, 고유 번호
vector<pair<int, int> > vii[100];

/*
1. 많이 재생된 장르
2. 장르 내에서 많이 재생된 노래
3. 장르 내 재생이 같은 노래중 고유번호가 낮은 노래
*/
bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    int idx = 0;
    vector<int> answer;
    vector<pair<int, string> > vp;
    for(int i=0;i<genres.size();i++) {
        msi[genres[i]] += plays[i];
        if(seq.count(genres[i]) == 0) {
            seq[genres[i]] = idx++;
        }
        vii[seq[genres[i]]].push_back({plays[i], i});
    }
    for(auto it : msi){
        vp.push_back({it.second, it.first});   
    }
    sort(vp.begin(), vp.end(), greater<pair<int, string> >());
    for(int i=0;i<idx;i++) {
        sort(vii[i].begin(), vii[i].end(), cmp);
    }
    for(int i=0;i<vp.size();i++) {
        string cur_genre = vp[i].second;
        if(vii[seq[cur_genre]].size() == 1) {
            answer.push_back(vii[seq[cur_genre]][0].second);       
        }else {
            for(int j=0;j<2;j++) {
                answer.push_back(vii[seq[cur_genre]][j].second);
            }
        }
    }
    return answer;
}