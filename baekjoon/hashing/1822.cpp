/*
[boj] 1822. 차집합 
https://www.acmicpc.net/problem/1822
*/

#include <iostream>
#include <set>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
set<int> s;
int main() 
{
    io;
    int A, B, tmp;
    cin>>A>>B;
    for(int i=0;i<A;i++){
        cin>>tmp;
        s.insert(tmp);
    }

    for(int i=0;i<B;i++){
        cin>>tmp;
        if(s.find(tmp) == s.end()) continue;
        else s.erase(s.find(tmp));
    }
    
    cout<<s.size()<<"\n";
    for(auto it : s)
        cout<<it<<" ";
    cout<<"\n";
    
    return 0;
}

