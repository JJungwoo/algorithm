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
    int i = n;
    while(i > 1 && seq[i] >= seq[i-1]){ // 5 4 3 2 1 start
        i--;
    }
    if(i <= 1){
        return false;
    }
    int j = n;
    while(seq[i-1] <= seq[j]){  
        j--;
    }
    swap(seq[i-1], seq[j]);
    j = n;
    while(i < j){
        swap(seq[i], seq[j]);
        i++;
        j--;
    }
    return true;
}

int main()
{
    io;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>seq[i];
    if(prev_permutation()){
        for(int i=1;i<=n;i++)
            cout<<seq[i]<<" ";
        cout<<"\n";
    }
    else 
        cout<<"-1\n";
    return 0;
}