/*
[BOJ] 1406. editor
*/
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int cmd;
    char *text;
    cin>>text;
    cin>>cmd;
    stack<char> lst;
    stack<char> dst;
    for(int i=0;i<text[i];i++){
        lst.push(text[i]);
    }
    while(cmd--){
        char input;
        cin>>input;
        if(input == 'L'){
            char buf;
            if(!lst.empty()){
                buf = lst.top();
                lst.pop();
            }
            dst.push(buf);
        }else if(input == 'D'){

        }else if(input == 'B'){

        }else {
            char insert;
            cin>>insert;
            lst.push(insert);
        }
    }



    return 0;
}