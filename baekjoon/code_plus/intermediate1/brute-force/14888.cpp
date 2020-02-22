/*
[BOJ] 14888. 연산자 끼워넣기
dfs 호출할 때, 바로 뒤에 숫자를 호출해서 dfs는 가능하다.
그런데 문제는 인덱스를 조합순열로 순회해야하는데...
어떻게 해야할까?...
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, op_cnt, max_ans = -1e10, min_ans = 1e10;
int numbers[11];
int formula[4]; // +, -, *, /
bool visited[11];

int calc(int a, int b, int op)
{
	//cout<<a<<" "<<b<<" , "<<op<<"\n";
	switch(op){
		case 0:
			return a+b;
		case 1:
			return a-b;
		case 2:
			return a*b;
		case 3:
			return a/b;
		default:
			break;
	}
	return 0;
}

void dfs(int idx, int sum){

	if(idx == n-1){
		max_ans = max(max_ans, sum);
		min_ans = min(min_ans, sum);
        return;
	}

	for(int j=0;j<4;j++){
        if(formula[j]){
            formula[j]--;
            dfs(idx+1, calc(sum, numbers[idx+1], j));
            formula[j]++;
        }
	}
}

int main()
{   
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>numbers[i];
    }
	
    for(int i=0;i<4;i++){
        cin>>formula[i];
		op_cnt += formula[i];
    }
	
	//cout<<op_cnt<<"\n";
    dfs(0, numbers[0]);

	cout<<max_ans<<"\n";
	cout<<min_ans<<"\n";

    return 0;
}
