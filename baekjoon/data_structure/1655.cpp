/*
[BOJ] 1655. 가운데를 말해요 
https://www.acmicpc.net/problem/1655
다시 풀어보기
최대 힙(오름차순) < 중간 값 < 최소 힙(내림차순)
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int n, input;
priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<int> > min_heap;

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>input;
        if(max_heap.empty())
            max_heap.push(input);
        else {
            if(min_heap.size() < max_heap.size())
                min_heap.push(input);
            else
                max_heap.push(input);
            
            if(min_heap.top() < max_heap.top()){
                int mintop = min_heap.top();
                int maxtop = max_heap.top();
                min_heap.pop();
                max_heap.pop();
                min_heap.push(maxtop);
                max_heap.push(mintop);
            }
        }
        cout<<max_heap.top()<<"\n";
    }
    return 0;
}

/*
priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<int> > min_heap;
int n,x;
int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        if(max_heap.empty())
            max_heap.push(x);
        else{
            if(max_heap.size() > min_heap.size()){
                min_heap.push(x);
            }else{
                max_heap.push(x);
            }

            if(max_heap.top() > min_heap.top()){
                int maxtop = max_heap.top();
                int mintop = min_heap.top();
                max_heap.pop();
                min_heap.pop();
                max_heap.push(mintop);
                min_heap.push(maxtop);
            }
        }
        cout<<max_heap.top()<<"\n";
    }
    return 0;
}
*/