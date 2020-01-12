/*
[BOJ] 9076. 점수 집계
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    io;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        vector<int> ans;
        for(int j=0;j<5;j++){
            int input; cin>>input;
            ans.push_back(input);
        }
        sort(ans.begin(), ans.end());
        if(ans[3] - ans[1] >= 4){
            cout<<"KIN\n";
            continue;
        }
        int res = 0;
        for(int i=1;i<4;i++) res += ans[i];
        cout<<res<<"\n";
    }
    return 0;
}
