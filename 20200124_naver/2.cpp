
#include <iostream>
#include <cstring>
using namespace std;
string msg;
int ldx, rdx;

bool check_palindrome(){
    //int len = msg.size();
    int rdx = msg.size()-1;
    while(ldx < rdx){
        cout<<msg[ldx]<<","<<msg[rdx]<<"\n";
        if(msg[ldx] != '?' && msg[rdx] != '?')
            if(msg[ldx] != msg[rdx])
                return false;
        ldx++;
        rdx--;
    }
   
    ldx = 0;
    rdx = msg.size()-1;

    while(ldx < rdx){
        cout<<msg[ldx]<<","<<msg[rdx]<<"\n";
        if(msg[ldx] == '?' && msg[rdx] == '?'){
            msg[ldx] = 'a';
            msg[rdx] = 'a';
        }
        else if(msg[ldx] == '?'){
            msg[ldx] = msg[rdx];
        }
        else if(msg[rdx] == '?'){
            msg[rdx] = msg[ldx];
        }
        ldx++;
        rdx--;
    }
    return true;
}
/*
string check_palindrome(){
    int len = msg.size();
    int rdx = msg.size()-1;
    while(ldx < rdx){
        cout<<msg[ldx]<<","<<msg[rdx]<<"\n";
        if(msg[ldx] != '?' && msg[rdx] != '?')
            if(msg[ldx] != msg[rdx])
                return "NO";
        ldx++;
        rdx--;
    }
        ldx = 0;
    rdx = msg.size()-1;

    while(ldx < rdx){
        cout<<msg[ldx]<<","<<msg[rdx]<<"\n";
        if(msg[ldx] == '?' && msg[rdx] == '?'){
            msg[ldx] = 'a';
            msg[rdx] = 'a';
        }
        else if(msg[ldx] == '?'){
            msg[ldx] = msg[rdx];
        }
        else if(msg[rdx] == '?'){
            msg[rdx] = msg[ldx];
        }
        ldx++;
        rdx--;
    }
    return msg;
}
*/

int main()
{
    cin>>msg;
    
    if(check_palindrome()){
        cout<<msg<<"\n";
    }
    else cout<<"NO\n";
    return 0;
}