/*
[BOJ] 10973. 이전 순열
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
int seq[10001];

bool prev_permutation(){
    
}

int main()
{
    io;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>seq[i];
    if(prev_premutation()){
        for(int i=1;i<=n;i++)
            cout<<seq[i]<<" ";
        cout<<"\n";
    }
    else 
        cout<<"-1\n";
    return 0;
}