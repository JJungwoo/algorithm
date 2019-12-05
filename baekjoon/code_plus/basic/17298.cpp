/*
[BOJ] 17298. 오큰수
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> ans(n, -1), arr(n);
    stack<int> stmp;
    for(int i=0;i<n;i++) cin>>arr[i];
    
    for(int i=0;i<n;i++){
        while(!stmp.empty() && arr[stmp.top()] < arr[i]){
            ans[stmp.top()] = arr[i];
            stmp.pop();
        }
        stmp.push(i);
    }

    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    

    return 0;
}