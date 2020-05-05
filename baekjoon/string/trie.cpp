#include <iostream>
#include <cstring>

#define alphabets 26
using namespace std;

int char_to_index(char c){
    return c - 'A';
}

struct trie{
    bool terminal;
    trie *children[alphabets];

    trie(): terminal(false){
        memset(children, 0, sizeof(children));
    }

    ~trie(){
        for(int i=0;i<alphabets;i++){
            if(children[i]) delete children[i];
        }
    }

    void insert(const char *key){
        if(*key == '\0'){
            terminal = true;
        }else {
            int index = char_to_index(*key);

            if(children[index] == 0)
                children[index] = new trie();
            children[index]->insert(key + 1);
        }
    }

    trie *find(const char * key){
        if(*key == 0){
            return this;
        }

        int index = char_to_index(*key);
        if(children[index] == 0){
            return NULL;
        }

        return children[index]->find(key + 1);
    }

    bool string_exist(const char * key){
        if(*key == 0 && terminal){
            return true;
        }

        int index = char_to_index(*key);
        if(children[index] == 0){
            return false;
        }

        return children[index]->string_exist(key + 1);
    }
};

int main(){

    trie * root = new trie();

    const char * words[5] = {"be", "bee", "can", "cat", "cd"};

    for(int i=0;i<5;i++){
        cout<<"insert : "<<words[i]<<"\n";
        root->insert(words[i]);
    }

    cout<<"be is "<<(root->find("be") == 0 ? "empty" : "find")<<"\n";
    cout<<"not is "<<(root->find("not") == 0 ? "empty" : "find")<<"\n";

    return 0;
}