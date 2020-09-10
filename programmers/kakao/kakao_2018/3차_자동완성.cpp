/*
[programmers] 2018 KAKAO BLIND RECRUITMENT [3차] 자동완성
https://programmers.co.kr/learn/courses/30/lessons/17685
*/

#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
#define ALPHABETS 26

struct trie {
    int cnt;
    bool term;
    trie *next[ALPHABETS];
    
    trie() : term(false) {
        memset(next, 0, ALPHABETS);
        cnt = 0;
    }
    ~trie() {
        for(int i=0;i<ALPHABETS;i++)
            if(next[i]) delete next[i];
    }
    int ctoi(const char *key) {
        return *key - 'a';
    }
    void insert(const char *key) {
        if(*key == '\0') term = true;
        else {
            int cur = ctoi(key);
            if(next[cur] == 0)
                next[cur] = new trie();
            next[cur]->cnt++;
            next[cur]->insert(key + 1);
        }
    }
    void find(const char *key, int &cnt) {
        if(*key == '\0') return ;
        int cur = ctoi(key);
        cnt++;
        if(next[cur]->cnt == 1) 
            return ;
        next[cur]->find(key + 1, cnt);
    }
};
int solution(vector<string> words) {
    int answer = 0;
    trie *root = new trie();
    for(auto it : words) {
        const char *tmp = it.c_str();
        root->insert(tmp);
    }
    for(auto it : words) {
        int cnt = 0;
        const char *tmp = it.c_str();
        root->find(tmp, cnt);
        answer += cnt;
    }
    return answer;
}