/*
[boj] 10610. 30
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
string n, ans;
vector<int> vn;
int sum;
bool possible;
int main()
{
    io;
    cin>>n;
    for(int i=0;i<n.size();i++){
        sum += n[i] - '0';
        vn.push_back(n[i] - '0');
        if(n[i] - '0' == 0) possible = true;
    }
    if(!possible || sum%3 != 0){
        cout<<"-1\n";
        return 0;
    }
    sort(vn.begin(), vn.end(), greater<int>());
    //sort(vn.begin(), vn.end()); 
    
    for(int i=0;i<vn.size();i++){
        ans += vn[i] + '0';
    }
    cout<<ans<<"\n";
    return 0;
}