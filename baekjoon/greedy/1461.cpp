/*
[boj] 1461. 도서관
https://www.acmicpc.net/problem/1461
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n,m,input,ans;
vector<int> go, back;
int main() 
{
    io;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>input;
        if(input < 0) back.push_back(-input);
        else go.push_back(input);
    }

    if(!go.empty()){
        sort(go.begin(), go.end());
        for(int i=go.size()-1;i>=0;i-=m)
            ans += go[i]*2;
    }
    
    if(!back.empty()){
        sort(back.begin(), back.end());
        for(int i=back.size()-1;i>=0;i-=m)
            ans += back[i]*2;
    }

    if(go.empty()) ans -= back.back();
    else if(back.empty()) ans -= go.back();
    else ans -= max(go.back(), back.back());
    cout<<ans<<"\n";

    return 0;
}
