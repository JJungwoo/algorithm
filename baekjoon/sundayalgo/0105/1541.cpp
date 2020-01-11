/*
[BOJ] 1541. 잃어버린 괄호
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

string formula;
vector<int> sum_arr;

int main()
{
    io;
    cin>>formula;
    int len = formula.size();
    int subcnt = 0, sumcnt = 0, sum = 0;
    for(int i=0;i<len;i++){
        bool chk = false;
        if(formula[i] == '-'){
            subcnt++;
        }else if(formula[i] != '-' && formula[i] != '+'){
            chk = true;
            sum += formula
        }

        if(chk){
            
        }
    }

    cout<<subcnt<<"\n";



    return 0;
}