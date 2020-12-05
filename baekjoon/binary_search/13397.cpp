/*
[boj] 13397. 구간 나누기 2 
https://www.acmicpc.net/problem/13397
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, M;
int nums[5001];
bool isSuccess(int mid, int sum) {
    int cnt = 1, min = sum, max = 0;
    for(int i=0;i<N;i++) {
        if(min > nums[i]) min = nums[i];
        if(max < nums[i]) max = nums[i];
        if(mid < max - min) {
            min = nums[i];
            max = nums[i];
            cnt++;
        }
    }
    return (cnt <= M);
}
int main() 
{
    io;
    int sum = 0;
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        cin >> nums[i];
        sum += nums[i];
    }
    int left = 0, right = sum;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(isSuccess(mid, sum)) {
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    cout<<right + 1<<"\n";
    return 0;
}