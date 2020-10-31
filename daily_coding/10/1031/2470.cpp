/*
[boj] 2470. 두 용액
https://www.acmicpc.net/problem/2470
*/

#include <iostream>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const long long INF = 1e10;
int N;
long long num[100001], diff = INF, answer[2];
int main() 
{
    io;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num[i];
    }
    sort(num, num+N);
    int left = 0, right = N-1;
    while(left < right) {
        long long sum = num[right] + num[left];
        if(llabs(sum) < diff) {
            diff = llabs(sum);
            answer[0] = num[left], answer[1] = num[right];
        }
        if(sum < 0)
            left++;
        else 
            right--;
    }
    cout<<answer[0]<<" "<<answer[1]<<"\n";
    return 0;
}