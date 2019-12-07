/*
[BOJ] 1406. editor
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int cmd;
    char text[100001];
    cin.getline(text, 100000);
    cin>>cmd;
    stack<char> lst;
    stack<char> dst;
    for(int i=0;i<text[i];i++){
        lst.push(text[i]);
    }
    while(cmd--){
        char input, buf;
        cin>>input;
        if(input == 'L'){
            if(!lst.empty()){
                buf = lst.top();
                lst.pop();
                dst.push(buf);
            }
        }else if(input == 'D'){
            if(!dst.empty()){
                buf = dst.top();
                dst.pop();
                lst.push(buf);
            }
        }else if(input == 'B'){
            if(!lst.empty()){
                lst.pop();
            }
        }else {
            char insert;
            cin>>insert;
            lst.push(insert);
        }
    }

    vector<char> ans;
	while(!lst.empty()){
		ans.push_back(lst.top());	
		lst.pop();
	}
    int len = ans.size();
    for(int i=len;i>=0;i--){
		cout<<ans[i];
    }
	while(!dst.empty()){
		cout<<dst.top();
		dst.pop();
	}
    return 0;
}