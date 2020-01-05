/*
[BOJ] 1543. 문서검색
dfs도 가능하지 않을까..
*/  
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

string str, word;

int main()
{
    io;
    getline(cin, str);
    getline(cin, word);
    int wlen = word.length(), cnt = 0, ans = 0, slen = str.length();
    if(wlen > slen){
        cout<<"0\n";
        return 0;
    }
    for(int i=0;i<slen;i++){
        cout<<i<<":"<<str[i]<<","<<cnt<<":"<<word[cnt]<<"\n";
        if(str[i] == word[cnt]){
            if(cnt == wlen - 1) {
                ans++;
                cnt = 0;
                continue;
            } else if(str[i+1] != word[cnt+1]) {
                cnt = 0;
                if(str[i] == word[cnt]) cnt++;
                continue;
            }
            cnt++;
        }else{
            cnt = 0;
            if(str[i] == word[cnt]){
                cnt++;
            }
        }
    }
    cout<<ans<<"\n";

    return 0;
}


/*
string str, word;
bool visited[2501];
int slen, wlen;

void dfs(int v){
    if(visited[v]) return;
    for(int i=0;i<wlen;i++){
        if(str[v] 
    }
}

int main()
{
    io;
    cin>>str;
    cin>>word;
    slen = str.length();
    wlen = word.length();
    for(int i=0;i<slen;i++){
        dfs(i);
    }
    return 0;
}
*/