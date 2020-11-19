#include <string>
#include <vector>

using namespace std;
int nsize, ans;
void dfs(vector<int> nums, int sum, int idx, int target) {
    if(idx > nsize) return;
    else if(idx == nsize) {
        if(sum == target) ans++;
        return;
    }
    dfs(nums, sum + nums[idx], idx + 1, target);
    dfs(nums, sum - nums[idx], idx + 1, target);
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    nsize = numbers.size();
    dfs(numbers, 0, 0, target);
    return answer = ans;
}
