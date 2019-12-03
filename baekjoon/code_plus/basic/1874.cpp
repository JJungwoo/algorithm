/*
[BOJ] 1874. 스택수열
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int n, pos = 0;
	cin>>n;
	vector<int> vt;
	vector<char> cvt;
	stack<int> st;
	for(int i=0;i<n;i++){
		int tmp; cin>>tmp;
		vt.push_back(tmp);
	}
	for(int i=1;i<=n;i++){
		if(i <= vt[pos]){
			cvt.push_back('+');
			st.push(i);
				while(st.top() == vt[pos]){ // && st.top() > vt[pos+1]){
					cvt.push_back('-');
					st.pop();
					pos++;
					if(st.size() <= 0) break;
				}
		}
	}
	bool check = true;
	while(pos < n && st.top() >= vt[pos]){
		cvt.push_back('-');
		st.pop();
		pos++;
		if(st.top() < vt[pos]) {check = false; break;}
	}
	if(!check || pos < n)
		cout<<"NO\n";
	else{
		for(int i=0;i<cvt.size();i++)
			cout<<cvt[i]<<"\n";
	}


	return 0;
}
