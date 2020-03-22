/*
[BOJ] 16637. 괄호 추가하기
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, ans;
string input;
vector<int> numbers;
vector<char> signs;

inline int cal(int a, int b, char sign){
    int ret = 0;
    switch(sign){
        case '+':
        ret = a + b;
        break;
        case '-':
        ret = a - b;
        break;
        case '*':
        ret = a * b;
        break;
        case '/':
        ret = a / b;
        break;
    }
    return ret;
}

void dfs(int cnt, int num1, int num2){
    if(cnt == numbers.size()){
        
        return;
    }
}

void solve(){
    int size = numbers.size();
    if(size = 1){
        cout<<numbers[0]<<"\n";
    }else if(size == 2){
        cout<<cal(numbers[0], numbers[1], signs[0]);
    }else {
        dfs(0, numbers[0], numbers[0]);
        cout<<ans<<"\n";
    }
}

int main()
{
    io;
    cin>>n;
    cin>>input;
    for(int i=0;i<input.size();i++){
        if((i+1%2) == 0){
            numbers.push_back(input[i]-'0');
        } else {
            signs.push_back(input[i]);
        }   
    }
    solve();
    return 0;
}

/*
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
*/