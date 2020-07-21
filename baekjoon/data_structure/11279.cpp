/*
[BOJ] 11279. 최대 힙
https://www.acmicpc.net/problem/11279
*/

#include <iostream>
#include <queue>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
priority_queue<int> pq;
int n, x;
int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x != 0)
            pq.push(x);
        else{
            if(!pq.empty()){
                cout<<pq.top()<<"\n";
                pq.pop();
            }else cout<<"0\n";
        }
    }
    return 0;
}