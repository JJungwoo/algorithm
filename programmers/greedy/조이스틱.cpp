#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string name) {
    int answer = 0;
    
    int nLen = name.length();
    int tmp = 0, turn = nLen - 1;
    
    for(int i=0;i<nLen;i++){
        int start = name[i] - 'A';
        int end = 'Z' - name[i] + 1;
        
        tmp += min(start, end);
        
        int next = i+1;
        while(next < nLen && name[next] == 'A') next++;
        
        turn = min(turn, i + nLen - next + min(i, nLen - next));
    }
    
    answer = tmp + turn;
    return answer;
}
