/*
[BOJ] 7785. 회사에 있는 사람
https://www.acmicpc.net/problem/7785
*/

#include <iostream>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
set<string> s;
int n;
string name, cmd;
int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>name>>cmd;
        if(cmd == "enter")
            s.insert(name);
        else
            s.erase(name);
    }
    vector<string> vp;
    for(auto it : s)
        vp.push_back(it);
    reverse(vp.begin(), vp.end());
    for(auto it : vp) cout<<it<<"\n";
    /*
    // set reverse loop
    set<string>::reverse_iterator key;
	for (key = s.rbegin(); key != s.rend(); key++) {
		cout << *key << "\n";
	}
    */
    return 0;
}