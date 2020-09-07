#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.size(), m = board[0].size();
    stack<int> st;
    
    for(auto cur : moves){
        for(int i=0;i<n;i++){
            if(board[i][cur-1]) {
                //cout<<board[i][cur-1]<<","<<st.size()<<"\n";
                if(!st.empty() && st.top() == board[i][cur-1]){
                    st.pop();
                    answer += 2;
                }else {
                    st.push(board[i][cur-1]);    
                }
                board[i][cur-1] = 0;
                break;
            }
        }
    }
        
    return answer;
}