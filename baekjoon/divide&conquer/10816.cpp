/*
[boj] 10816. 숫자 카드 2
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, M;
map<int, int> m;
int main()
{
    io;
    cin>>N;
    for(int i=0;i<N;i++){
        int tmp; cin>>tmp;
        auto it = m.find(tmp);
        if(it == m.end()) m.insert(make_pair(tmp, 1));
        else it->second += 1;
    }
    //sort(m.begin(), m.end());
    cin>>M;
    for(int i=0;i<M;i++){
        int tmp; cin>>tmp;
        auto it = m.lower_bound(tmp);
        if(it->first != tmp) cout<<"0 ";
        else cout<<it->second<<" ";
        //cout<<it->first<<":"<<it->second<<"\n";
        //cout<<"tmp: "<<m.lower_bound(tmp);
    }
    cout<<"\n";
    for(auto it : m){
        cout<<it.first<<":"<<it.second<<"\n";
    }

    return 0;
}