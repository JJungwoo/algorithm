/*
[boj] 1806. 부분합 
https://www.acmicpc.net/problem/1806
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long long N, S, psum[100001], num[100001], answer = 1e10+1;
int main() 
{
    io;
    cin >> N >> S;
    for(int i=0;i<N;i++) {
        cin >> num[i];
        if(i > 0) psum[i] = num[i] + psum[i-1];
        else psum[i] = num[i];
    }
    int left = 0, right = 1;
    while(left < N || right < N) {
        
        if(psum[right] - psum[left-1] >= S) {
            //answer = min(answer, right - left);
            cout<<right<<" , "<<left<<" "<<psum[right]<<" - "<<psum[left]<<"\n";   
            answer = right - left + 1;
        }
        if(num[right] > num[left]) right++;
        else left++;
    }
    if(answer == 1e10+1) answer = 0;
    cout<<answer<<"\n";
    return 0;
}
