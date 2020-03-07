/*
[BOJ] 1339. 단어 수학
2
AAA
AAA
1998
A = 9
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, word_cnt;
string msg[10];
bool word[26];
bool visited[10];

void solve(int cnt)
{
    if(cnt == word_cnt){

        return;
    }

    for(int i=0;i<10;i++){
        if(visited[i]) continue;
        visited[i] = true;
        solve(cnt + 1);
        visited[i] = false;
    }
}

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>msg[i];
        for(int j=0;j<msg[i].size();i++){
            if(word[msg[i][j] - 'A'] == false){
                word_cnt++;
                word[msg[i][j] - 'A'] = true;
            }
        }
    }
    solve(0);

    return 0;
}