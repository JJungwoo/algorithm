/*
[BOJ] 3568. iSharp 
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int cnt, sidx, eidx;
string input;
vector<string> cmd;
int main()
{
    io;
    getline(cin, input);
    for(int i=0;i<input.size();i++){
        if(input[i] == ' '){
            cnt++;
            cout<<input.substr(0,i)<<"\n";
            cmd.push_back(input.substr(sidx, i));
            sidx = i;
        }else {
            cout<<input[i];
        }
    }
cout<<"\n";
    for(int i=0;i<cmd.size();i++){
        cout<<i<<":"<<cmd[i]<<"\n";
    }
    return 0;
}