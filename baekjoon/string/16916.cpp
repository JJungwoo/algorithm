/*
[BOJ] 16916. 부분 문자열 
*/
#include <iostream>
#include <string>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
string input, tmp;
int main()
{
    io;
    cin>>input>>tmp;
    int ans = 0;
    int isize = input.size(), tsize = tmp.size();
    for(int i=0;i<isize - tsize;i++){
        bool check = true;
        for(int j=0;j<tsize;j++){
            if(input[i + j] != tmp[j]) {check = false;
                cout<<input[i]<<","<<tmp[j]<<"\n";
            }
        }
        if(check) {
            ans = 1;
            break;
        }
    }
    cout<<ans<<"\n";

    return 0;
}