/*
[boj] 10989. 수 정렬하기 3
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, max_val;
int v[10001];
int main()
{
	io;
	cin >> n;
	for(int i=0;i<n;i++) {
		int tmp; cin>>tmp;
		v[tmp]++;
		if(max_val < tmp) max_val = tmp;
	}
    for(int i=1;i<=max_val;i++)	
		if(v[i] != 0)
			for(int j=0;j<v[i];j++) cout<<i<<"\n";
		
	return 0;
}
