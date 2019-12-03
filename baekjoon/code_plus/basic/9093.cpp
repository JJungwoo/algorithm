/*
[BOJ] 9093. 단어 뒤집기
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
	int n;
	cin>>n;
	cin.ignore();
	while(n--){
		char msg[1001];
		cin.getline(msg, 1000, '\n');
		stack<char> cStack;
		for(int i=0;i<strlen(msg);i++){
			if(msg[i] == ' '){
				int CSTsize = cStack.size();
				for(int j=0;j<CSTsize;j++){
					cout<<cStack.top();
					cStack.pop();
				}
				cout<<" ";
				continue;
			}
			if(msg[i] != ' ' || msg[i] != EOF) cStack.push(msg[i]);
		}
		int CSTsize = cStack.size();
		for(int j=0;j<CSTsize;j++){
			cout<<cStack.top();
			cStack.pop();
		}
		cout<<"\n";
	}
	return 0;
}