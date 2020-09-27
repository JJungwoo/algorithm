/*
[boj] 2504. 괄호의 값
https://www.acmicpc.net/problem/2504
*/

#include <iostream>
#include <string>
#include <stack>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main() 
{
    io;
    int answer = 0;
    string input;
    stack<int> s;
    bool check = true;
    cin >> input;
    int open = 0, close = 0, sum = 1;
    for(int i=0;i<input.size();i++) {
        if('(' != input[i] && ')' != input[i] && '[' != input[i] && ']' != input[i]) {
            check = false;
            break;
        }
        if('(' == input[i]) {
            open++;
            s.push(-2);
        }else if('[' == input[i]) {
            open++;
            s.push(-3);
        }else if(')' == input[i]) {
            close++;
            if(open < close ) {
                check = false;
                break;
            }
            if(!s.empty() && s.top() > 0) {
                int tmp1 = s.top();
                s.pop();    // 숫자
                if(s.top() != -2) {
                    check = false;
                    break;
                }
                s.pop();
                if(!s.empty() && s.top() > 0) {
                    int tmp2 = s.top();
                    s.pop();
                    s.push(tmp1 * 2 + tmp2);
                }else
                    s.push(tmp1 * 2);
            }else if(!s.empty()){
                if(s.top() != -2) {
                    check = false;
                    break;
                }
                s.pop();
                if(!s.empty() && s.top() > 0) {
                    int tmp = s.top();
                    s.pop();
                    s.push(tmp + 2);
                }else
                    s.push(2);
            }
        }else if(']' == input[i]) {
            close++;
            if(open < close) {
                check = false;
                break;
            }
            if(!s.empty() && s.top() > 0) {
                int tmp1 = s.top();
                s.pop();    // 숫자
                if(s.top() != -3) {
                    check = false;
                    break;
                }
                s.pop();    // 괄호
                if(!s.empty() && s.top() > 0) {
                    int tmp2 = s.top();
                    s.pop();
                    s.push(tmp1 * 3 + tmp2);
                }else
                    s.push(tmp1 * 3);
                
            }else if(!s.empty()){
                if(s.top() != -3) {
                    check = false;
                    break;
                }
                s.pop();
                if(!s.empty() && s.top() > 0) {
                    int tmp = s.top();
                    s.pop();
                    s.push(tmp + 3);
                }else 
                    s.push(3);
            }
        }
    }

    while(check && !s.empty() && open == close){
        int tmp = s.top();
        s.pop();
        if(tmp < 0) continue;
        answer += tmp;
    }
    cout<<answer<<"\n";
    return 0;
}

