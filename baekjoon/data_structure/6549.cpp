/*
[boj] 6549. 히스토그램에서 가장 큰 직사각형
https://www.acmicpc.net/problem/6549
*/

#include <iostream>
#include <stack>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef unsigned long long ull;
ull histogram[100001];
int main() 
{
    io;
    int N;
    while(true) {
        cin >> N;
        if(N == 0) break;
        ull answer = 0;
        stack<int> s;
        for(int i=0;i<N;i++) {
            cin >> histogram[i];
        }
        histogram[N] = 0;
        for(int i=0;i<=N;i++) {
            while(!s.empty() && histogram[s.top()] >= histogram[i]) {
                int j = s.top();
                s.pop();
                int w = -1;
                if(s.empty())
                    w = i;
                else 
                    w = (i - s.top() - 1);
                answer = max(answer, histogram[j] * w);
            }
            s.push(i);
        }
        cout<<answer<<"\n";
    }
    return 0;
}