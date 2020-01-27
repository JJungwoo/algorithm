/*
[BOJ] 14501. 퇴사 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

struct work{
    int day, pay;
    work(int _day, int _pay):day(_day), pay(_pay){}
};

int n, ans;
vector<work> works;


void dfs(int idx, int value){
    if(ans < value) ans = value;
    for(int i=idx;i<n;i++){
        if(i + works[i].day <= n){
            //cout<<idx<<" + "<<works[i].day<<", "<<value<<"\n";
            dfs(i + works[i].day, value + works[i].pay);
        }
    }
}

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        works.push_back(work(a,b));
    }

    dfs(0,0);
    cout<<ans<<"\n";

    return 0;
}