#include <string>
#include <vector>
using namespace std;
typedef long long ll;
ll find(vector<int> tmp, int value){
    ll sum = 0;
    for(auto it : tmp){
        sum += min(it, value);
    }
    return sum;
}
int solution(vector<int> budgets, int M) {
    int answer = 0, sum = 0, max_val = 0;
    for(auto it : budgets){
        sum += it;
        max_val = max(max_val, it);
    }
    int lo = 0, hi = 1000000001;
    while(lo < hi){
        int mid = (lo+hi)/2;
        if(find(budgets, mid) >= M){
            hi = mid;
        }else{
            lo = mid + 1;
        }
    }
    answer = hi - 1;
    
    if(sum <= M && answer > M) return max_val;
    return answer;
}
