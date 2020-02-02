/*
[BOJ] 1431. 시리얼 번호
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
string stmp[1001];

bool compare(string a, string b){
    if(a.size() > b.size()){
        return false;
    } else if(a.size() < b.size()) return true;

    int len = a.size(), acnt = 0, bcnt = 0;
    for(int i=0;i<len;i++){
        if(a[i] >= '0' && a[i] <= '9') acnt += a[i] - '0';
        if(b[i] >= '0' && b[i] <= '9') bcnt += b[i] - '0';
    }
    if(acnt != bcnt)
        return acnt < bcnt; 
    return a < b;
}

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>stmp[i];
    }

    sort(stmp, stmp+n, compare);
    for(int i=0;i<n;i++){
        cout<<stmp[i]<<"\n";
    }
    return 0;
}