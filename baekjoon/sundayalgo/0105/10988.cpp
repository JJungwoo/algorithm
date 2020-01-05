/*
[BOJ] 10886. 0 = not cute / 1 = cute
*/
#include <iostream>
#include <string>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

string str;
int lchk, rchk;
int main()
{
    io;
    cin>>str;
    int len = str.length();
    rchk = len - 1;
    while(1){
        if(str[lchk] == str[rchk]){
            lchk++;
            rchk--;
            if(lchk >= rchk) {
                cout<<"1\n";
                return 0;
            }
        }else {
            cout<<"0\n";
            return 0;
        }
    }

    return 0;
}