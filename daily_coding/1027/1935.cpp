/*
[boj] 1935. 후위 표기식2
https://www.acmicpc.net/problem/1935
*/

#include <iostream>
#include <string>
#include <stack>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, num[27];
string input;
stack<double> s;
inline int check(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/') return 1;
    else return 0;
}
inline double cal(double A, double B, char op) {
    switch(op) {
        case '+': return A+B;
        case '-': return A-B;
        case '*': return A*B;
        case '/': return A/B;
    }
    return 0;
}
int main() 
{
    io;
    
    cin >> N;
    cin >> input;
    for(int i=0;i<N;i++) {
        cin >> num[i];
    }
    for(auto c : input) {
        if(check(c) != 0 && s.size() >= 2) {
            double a = s.top(); s.pop();
            double b = s.top(); s.pop();
            double value = cal(b, a, c);
            s.push(value);
        }
        else s.push(num[c-'A']);
    }
    cout.setf(ios::fixed);
    cout.precision(2);
    cout<<s.top()<<"\n";
    return 0;
}