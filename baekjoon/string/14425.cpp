/*
[BOJ] 14425. 문자열 집합
*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define alphabets 26
int n, m, ans;

struct trie{
    trie *next[alphabets];
    bool term;

    trie() : term(false){
        memset(next, 0, sizeof(next));
    }   
    ~trie() {
        for(int i=0;i<alphabets;i++){
            if(next[i]) delete next[i];
        }
    }
    int ctoi(char c){
        return c - 'a';
    }

    void insert(const char *key){
        if(*key == '\0') term = true;
        else {
            int cur = ctoi(*key);
            if(next[cur] == 0)
                next[cur] = new trie();
            next[cur]->insert(key + 1);
        }
    }

    bool find(const char *key){
        if(*key == '\0' && term) return true;
        int cur = ctoi(*key);
        if(next[cur] == 0) return false;
        return next[cur]->find(key+1);
    }
};

int main()
{
    io;
    cin>>n>>m;
    trie *root = new trie();
    for(int i=0;i<n;i++){
        char tmp[500]; cin>>tmp;
        root->insert(tmp);
    }
    for(int i=0;i<m;i++){
        char tmp[500]; cin>>tmp;
        if(root->find(tmp)){
            ans++;
        }
    }
    cout<<ans<<"\n";
    return 0;
}