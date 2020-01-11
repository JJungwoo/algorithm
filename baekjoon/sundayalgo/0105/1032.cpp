/*
[BOJ] 1032. 명령 프롬프트
*/
#include <iostream>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
string str[51];

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str[i];
    }
    int len = str[0].size();
    for(int i=0;i<len;i++){
        int cnt = 0;
        char chk = str[0][i];
        for(int j=0;j<n;j++){
            //cout<<chk<<"<>"<<str[j][i]<<"\n";
            if(chk == str[j][i])
                cnt++;
        }
        //cout<<":"<<cnt<<"\n";
        if(cnt == n)
            cout<<str[0][i];
        else
            cout<<"?";
    }
    cout<<"\n";
    return 0;
}