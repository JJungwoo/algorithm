#include <string>
#include <vector>
using namespace std;
#define MOD 1000000007

int solution(int n, vector<int> money) {
    int answer = 0;
    vector<int> dp(n+1,0);
    dp[0] = 1;
    for(auto it : money) {
        for(int i=1;i<=n;i++) {
            if(i - it >= 0) {
                dp[i] += dp[i - it] % MOD;
            }
        }
    }
    return answer = (dp[n] % MOD);
}