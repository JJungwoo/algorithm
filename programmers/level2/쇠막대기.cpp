#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string arrangement) {
    int answer = 0, onlaser = 0;
    stack<char> s;
    for(int i=0;i<arrangement.length();i++){
        if(arrangement[i] == '('){
            s.push(arrangement[i]);
            onlaser = 1;
        } else {
            if(onlaser) {
                s.pop();
                if(s.size() > 0) 
                    answer += s.size();
                onlaser = 0;
            } else {
                s.pop();
                answer++;
            }
        }
        //cout<<arrangement[i]<<":"<<answer<<" stack: "<<s.size()<<"\n";
    }
    return answer;
}
