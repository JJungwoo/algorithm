/*
[boj] 1406. 에디터
https://www.acmicpc.net/problem/1406
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N;
string input_str;
stack<char> left_stack, right_stack;
void move_left() {
    if (!right_stack.empty()) {
        left_stack.push(right_stack.top());
        right_stack.pop();
    }
}
void move_right() {
    if (!left_stack.empty()) {
        right_stack.push(left_stack.top());
        left_stack.pop();
    }
}
void remove_left() {
    if (!right_stack.empty()) {
        right_stack.pop();
    }
}
void append_left() {
    char ch; cin >> ch;
    right_stack.push(ch);
}

int main() 
{
    io;
    cin >> input_str;
    for(auto it : input_str) {
        right_stack.push(it);
    }
    cin >> N;
    while(N--) {
        char cmd; cin >> cmd;
        switch(cmd) {
            case 'L':
            move_left();
            break;
            case 'D':
            move_right();
            break;
            case 'B':
            remove_left();
            break;
            case 'P':
            append_left();
            break;
        }
    }
    string answer = "";
    while(!right_stack.empty()) {
        answer += right_stack.top();
        right_stack.pop();
    }
    reverse(answer.begin(), answer.end());
    while(!left_stack.empty()) {
        answer += left_stack.top();
        left_stack.pop();
    }
    cout<<answer<<"\n";
    return 0;
}