/*
[BOJ] 1759. 암호 만들기 
최소 한 개의 모음과 최소 두 개의 자음으로 구성

*/
#include <iostream>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int l,c;
char dict[16];
char vowel[5] = {'a', 'e', 'i', 'o', 'u'};

int main()
{
	io;
	cin>>l>>c;
	for(int i=0;i<c;i++) cin>>dict[i];
	sort(dict, dict+l);
	
	do{
		int vcnt = 0, cocnt = 0;
		for(int i=0;i<l;i++){
			if(dict[i] == 'a' || 

			cout<<dict[i]<<" ";
		}

		cout<<"\n";
	}while(next_permutation(dict, dict+l));

	return 0;
}

