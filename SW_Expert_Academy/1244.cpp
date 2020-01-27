/*
[SW_EA] 14889. [S/W 문제해결 응용] 2일차 - 최대 상금
문자열도 배열로 인덱싱 접근하면 값을 비교할 수 있다.
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

string a;
int n, ans;

void dfs(int v, int cnt){
    if(cnt == n){
        ans = max(ans, stoi(a));
        return;
    }
    int len = a.size();
    for(int i=v;i<len;i++){
        for(int j=i+1;j<len;j++){
            if(a[i] <= a[j]){
                swap(a[i], a[j]);
                dfs(i, cnt + 1);
                swap(a[j], a[i]);
            }
        }
    }
}

int main()
{
    io;
    int test_case;
	int T;
    
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>a;
        cin>>n;
        ans = 0;
        dfs(0,0);
        cout<<"#"<<test_case<<" "<<ans<<"\n";
	}


    return 0;
}