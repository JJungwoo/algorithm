/*
[boj] 4358. 생태학
https://www.acmicpc.net/problem/4358
https://beenpow.github.io/sweab/boj/%EB%B0%B1%EC%A4%80/2020/03/15/BOJ-4358/
map: https://slllju.tistory.com/94

*/

#include <iostream>
#include <vector>
#include <cstring>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int MAXCHAR = 96;
struct trie {
    int count;
    bool end;
    struct trie* next[MAXCHAR];
    trie() : end(false), count(1) {
        memset(next, 0, sizeof(next));
    }
    ~trie() {
        for(int i=0;i<MAXCHAR;i++)
            if(next[i])
                delete next[i];
    }
    inline int ctoi(const char c) {
        return c - 32;
    }
    void insert(const char *key) {
        if(*key == '\0') end = true;
        else {
            int cur = ctoi(*key);
            if(next[cur] == NULL)
                next[cur] = new trie;
            next[cur]->insert(key + 1);
        }
    }
    trie* find(const char* key) {
        if(*key == '\0') return this;
        int cur = ctoi(*key);
        if(next[cur] == NULL) return NULL;
        return next[cur]->find(key + 1);
    }
};

int main() 
{
    io;
    int total = 0;
    char input[32];

    struct trie root;
    struct trie* where;
    vector<string> name_list;

    while(!cin.getline(input, 31).eof()) {
        total++;
        if((where = root.find(input)) == NULL) {
            root.insert(name);
            name_list.push_back(name);
        }else
            where->count++;
    }

    return 0;
}

