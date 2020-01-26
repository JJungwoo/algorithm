/*
[BOJ] 1759. 암호 만들기 
최소 한 개의 모음과 최소 두 개의 자음으로 구성
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

// dfs failed...

int l, c;
char dict[16];
char output[6];

void dfs(int x, int count, int vcnt, int jcnt) {
	if(count == l && vcnt >= 1 && jcnt >= 2){
		for(int i=0;i<l;i++){
			cout<<output[i];
		}
		cout<<"\n";
		return;
	}

	for(int i=x;i<c;i++){
		if(dict[i] == 'a' || dict[i] == 'e' || dict[i] == 'i' ||
			dict[i] == 'o' || dict[i] == 'u' )
		{
			vcnt++;
			output[count] = dict[i];
			dfs(i + 1, count + 1, vcnt, jcnt);
			vcnt--;
		} else {
			jcnt++;
			output[count] = dict[i];
			dfs(i + 1, count + 1, vcnt, jcnt);
			jcnt--;
		}
	}

}

int main()
{
	io;
	cin>>l>>c;
	for(int i=0;i<c;i++) cin>>dict[i];
	sort(dict, dict+c);
	
	dfs(0,0,0,0);

	return 0;	
}


// next_permutation fail..
/*
int l, c;
char dict[16];
char vowel[5] = {'a', 'e', 'i', 'o', 'u'};

int main()
{
	io;
	cin>>l>>c;
	for(int i=0;i<c;i++) cin>>dict[i];
	sort(dict, dict+l);
	
	do{
		int vcnt = 0, check = 1;
		for(int i=0;i<c;i++){
			if(dict[i] == 'a' || dict[i] == 'e' || dict[i] == 'i' ||
				dict[i] == 'o' || dict[i] == 'u' )
			{
				if(vcnt >= 2)
					continue;
				vcnt++;
			}

			cout<<dict[i]<<" ";
			if(check == l){
				break;
			}
			check++;
		}

		cout<<"\n";
	}while(next_permutation(dict, dict+l));

	return 0;
}
*/