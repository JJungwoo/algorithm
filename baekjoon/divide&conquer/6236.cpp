/*
[boj] 6236. 용돈 관리 
https://www.acmicpc.net/problem/6236
어떻게 할지 감이 안와서 검색해서 이분 탐색인 걸 알았다. 
이분 탐색을 통해 k 값을 추론하여 문제에서 제시한 상황 그대로 구현하면 된다.
ref : https://jaimemin.tistory.com/1131
*/

#include <iostream>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n,m;
vector<int> pays;
bool find(int k){
    int cnt = 1, sum = k;
    for(auto it : pays){
        if(k < it) 
            return false;

        if(sum - it < 0){
            sum = k;
            cnt++;
        }
        sum -= it;
    }
    return m >= cnt;
}
int solve(int sum){
    int lo = 0, hi = sum;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(find(mid)){
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return hi+1;
}
int main() 
{
    io;
    cin>>n>>m;
    pays.resize(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        cin>>pays[i];
        sum += pays[i];
    }
        
    cout<<solve(sum)<<"\n";
    return 0;
}

