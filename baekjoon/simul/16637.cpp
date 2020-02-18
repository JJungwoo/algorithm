/*
[BOJ] 16637. 괄호 추가하기
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

char formula[19];
int number[19], result[19];
int n, fcnt, ncnt, ans;

int calc(int a, int b, char form){
    int res = 0;

    switch(form){
		case '+':
        res = a+b;
        break;
		case '-':
        res = a-b;
        break;
		case '*':
        res = a*b;
        break;
    }

    return res;
}

void dfs(int cnt, int sum){

    if(cnt >= fcnt){
        ans = max(ans, sum);
		return;
    }
	
	int res = calc(sum, number[cnt+1], formula[cnt]);
	dfs(cnt+1, res);

	if(cnt+1 < fcnt){
		int af_res = calc(number[cnt+1], number[cnt+2], formula[cnt+1]);
		int cur_res = calc(sum, af_res, formula[cnt]);
		dfs(cnt+2, cur_res);
	}
}

void solve(){
	if(n == 1){
		cout<<number[0]<<"\n";
	}
	else if(n == 3){
		cout<<calc(number[0], number[1], formula[0])<<"\n";
	}
	dfs(0, number[0]);
	cout<<ans<<"\n";
}

int main()
{
    io;
    cin>>n;
	
	string input_formula;
	cin>>input_formula;
    for(int i=0;i<n;i++){
        if(i%2==0) number[ncnt++] = input_formula[i] - '0';
        else formula[fcnt++] = input_formula[i];
    }

    solve();
    return 0;
}
