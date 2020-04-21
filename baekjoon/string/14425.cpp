/*
[BOJ] 14425. 부분 문자열 
*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
vector<string> vm, vn;
int n, m, ans;
int main()
{
    io;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string tmp; cin>>tmp;
        vn.push_back(tmp);
    }
    for(int i=0;i<m;i++){
        string tmp; cin>>tmp;
        vm.push_back(tmp);   
    }
    
    cout<<ans<<"\n";
    return 0;
}