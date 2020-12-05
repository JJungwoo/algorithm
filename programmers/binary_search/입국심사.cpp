#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool isSuccess(long long n, long long mid, vector<int> times) {
    long long cnt = 0;
    for(int i=0;i<times.size();i++) {
        if(mid < times[i]) break;
        cnt += (mid / times[i]);
    }
    return (cnt >= n) ? true : false;
}
long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    long long left = 1, right = (long long)n * (long long)times.back();
    while(left <= right) {
        long long mid = (left + right) / 2;
        if(isSuccess((long long)n, mid, times)) {
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return answer = right + 1;
}