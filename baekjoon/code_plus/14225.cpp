/*
[BOJ] 14225. 부분수열의 합
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
int numbers[11];
int formula[4]; // +, -, *, /
void solve(int cnt){
    if(cnt == )
}

int calc(vector<int> &a, vector<int> &b){
    int n = a.size();
    int ans = a[0];
    for(int i=1;i<n;i++){
        if(b[i-1] == 0){
            ans = ans + a[i];
        } else if (b[i-1] == 1){
            ans = ans - a[i];
        }
    }
}

int main()
{   
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>numbers[i];
    }
    for(int i=0;i<4;i++){
        cin>>formula[i];
    }
    solve();
    return 0;
}
