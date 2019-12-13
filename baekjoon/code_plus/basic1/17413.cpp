/*
[BOJ] 17413. 단어 뒤집기2 
*/
#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
int main()
{	
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	stack<char> output;
    char ex_msg[100001];
	bool check = false;
    cin.getline(ex_msg, 100000, '\n');
	int msg_len = strlen(ex_msg);
	for(int i=0;i<msg_len;i++){
		if(ex_msg[i] == '<'){
			while(!output.empty()){
				cout<<output.top();
				output.pop();
			}
			cout<<ex_msg[i];
			check = true;
		}else if(ex_msg[i] == '>'){
			cout<<ex_msg[i];
			check = false;
		}
		else if(check){
			cout<<ex_msg[i];
		}else {
			output.push(ex_msg[i]);
		}
    }
	while(!output.empty()){
		cout<<output.top();
		output.pop();
	}
	cout<<"\n";
    return 0;
}