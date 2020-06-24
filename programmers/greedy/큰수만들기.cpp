#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(string number, int k) {
    string answer = "";

    stack<char> s;
    int size = number.length() - k;

    for(int i = 0; i < number.length(); i++){

        char ch = number[i];
        for(; (!s.empty()) &&  k > 0; k--){
            char s_top = s.top();
            if(s_top >= ch) break;
            s.pop();
        }
        s.push(ch);
    }

    while(s.size() != size) s.pop();

    while(!s.empty()){
        char x = s.top();
        answer = x + answer;
        s.pop();
    }
    return answer;
}
