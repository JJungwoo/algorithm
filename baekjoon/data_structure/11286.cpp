/*
[boj] 11286. 절댓값 힙 
https://www.acmicpc.net/problem/11286
*/

#include <iostream>
#include <queue>
#include <cmath>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
struct cmp {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        if(a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int> >, cmp> pq;
int main() 
{
    io;
    int N;
    cin >> N;
    while(N--) {
        int X;
        cin >> X;
        if(X == 0) {
            if (pq.empty())
                cout<<"0\n";
            else {
                cout<<pq.top().second<<"\n";
                pq.pop();
            }
        }else
            pq.push(make_pair(abs(X), X));
    }
    return 0;
}