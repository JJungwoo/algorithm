#include <iostream>
#include <cstring>
#include <cstdio>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;



int main()
{
    io;
    int tcase;
    cin>>tcase;
    while(tcase--){
        string in;
        cin>>in;
        int size = in.size();
        for(int i=size-1;i>0;i--){
            if(in[i] - '0' > in[i-1] - '0'){
                in[i] -= '0'
                for(int j=i-1;j<size-1;j++){
                    in[i] = '9';
                }
            }
        }

        cout<<in<<"\n";
    }
    return 0;
}

/*

long long in;
        cin>>in;
        int atmp = 10, btmp = 100;
        while(btmp < in){
            int aval = in % atmp / (atmp/10), bval = in % btmp / atmp;
            if(aval > bval){

            }
            atmp *= 10, btmp *= 10;
        }

*/