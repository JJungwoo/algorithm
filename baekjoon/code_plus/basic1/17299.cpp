/*
[BOJ] 17299.오등큰수
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    int hash_table[1000001] = {0,};
    int n;
    cin>>n;
    vector<int> ans(n, -1), arr(n);
    stack<int> stmp;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        hash_table[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        while(!stmp.empty() && hash_table[arr[stmp.top()]] < hash_table[arr[i]]){
            ans[stmp.top()] = arr[i];
            stmp.pop();
        }
        stmp.push(i);
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    return 0;
}