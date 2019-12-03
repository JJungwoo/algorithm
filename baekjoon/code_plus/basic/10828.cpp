/*
[BOJ] 10828. stack
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	stack<int> myStack;
	int n;
	cin>>n;
	while(n--){
		string msg;
		cin>>msg;
		if(msg == "push"){
			int a;
			cin>>a;
			myStack.push(a);
		}else if(msg == "pop"){
			if(myStack.empty()){
				cout<<"-1\n";
				continue;	
			}
			cout<<myStack.top()<<"\n";
			myStack.pop();
		}else if(msg == "top"){
			if(myStack.empty()){
				cout<<"-1\n";
				continue;	
			}
			cout<<myStack.top()<<"\n";
		}else if(msg == "size"){
			cout<<myStack.size()<<"\n";
		}else if(msg == "empty"){
			cout<<myStack.empty()<<"\n";
		}
	}

	return 0;
}

