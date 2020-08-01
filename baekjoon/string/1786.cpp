/*
[boj] 1786. 찾기
https://www.acmicpc.net/problem/1786
*/

#include <iostream>
#include <string>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
string t, p;
int fail[10000001];
int main() 
{
    io;
    getline(cin, t);
    getline(cin, p);

    for(int i=1,j=0;i<p.size();i++) {
        while(j > 0 && p[i] != p[j])
            j = fail[j - 1];
        if(p[i] == p[j]) 
            fail[i] = ++j;
    }

    vector<int> ans;
    for(int i=0, j=0;i < t.size();i++) {
        while(j > 0 && t[i] != p[j]) 
            j = fail[j-1];
        if(t[i] == p[j]) {
            if(j == p.size() - 1) {
                ans.push_back(i - p.size() + 2);
                j = fail[j];
            }
            else ++j;
        }
    }

    cout<<ans.size()<<"\n";
    for(auto it : ans)
        cout<<it<<" ";
    cout<<"\n";
    return 0;
}

