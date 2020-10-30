/*
[boj] 16638. 괄호 추가하기 2 
https://www.acmicpc.net/problem/16638
*/

#include <iostream>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int ans = -2147483648;
vector<int> numbers;
vector<char> signs;
inline int operate(int num1, int num2, char formula) {
    switch(formula) {
        case '+' : return num1 + num2;
        case '-' : return num1 - num2;
        case '*' : return num1 * num2;
    }
    return 0;
}
void solve(int idx, int sum) {
    cout<<idx<<","<<sum<<"\n";
    if(idx >= numbers.size()-1) {
        ans = max(ans, sum);
        return ;
    }

    if(idx + 2 < numbers.size()) {
        int tmp = 0;
        if((signs[idx] == '+' || signs[idx] == '-') && signs[idx+1] == '*'){
            tmp = operate(numbers[idx + 1], numbers[idx + 2], signs[idx + 1]);
            solve(idx + 2, operate(sum, tmp, signs[idx]));
        }else{
            tmp = operate(sum, numbers[idx + 1], signs[idx]);
            solve(idx + 2, operate(tmp, numbers[idx + 2], signs[idx + 1])); 
        }
    }else 
        solve(idx + 1, operate(sum, numbers[idx + 1], signs[idx]));
}
int main() 
{
    io;
    int N;
    cin >> N;
    for(int i=1;i<=N;i++) {
        int num;
        char sign;
        if(i % 2 == 0) {
            cin >> sign;
            signs.push_back(sign);
        }else{
            cin >> num;
            numbers.push_back(num);
        }
    }
    solve(0, numbers[0]);
    cout << ans << "\n";
    return 0;
}

