/*
[BOJ] 1541. 잃어버린 괄호
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

string formula;

int main()
{
    io;
    cin>>formula;
    int len = formula.size();
    int val = 0, mul = 1, flag = 1, ans = 0;
    for(int i=0;i<len;i++){
        if(formula[i] == '-'){
            flag = -1;
            ans += val;
            val = 0;
        }else if(formula[i] == '+'){
            ans += val;
            val = 0;
        }else {
            val *= 10;
            val += (formula[i]-'0')*flag;
        }
    }
    if(val) ans += val;
    cout<<ans<<"\n";

    return 0;
}