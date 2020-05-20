/*
[boj] 1744. 수 묶기
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, sum;
vector<int> arr, brr;   // +, -
int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp; cin>>tmp;
        if(tmp <= 0) brr.push_back(tmp);
        else arr.push_back(tmp);
    }
    
    sort(arr.begin(), arr.end(), greater<int>());
    sort(brr.begin(), brr.end());
    
    if(!arr.empty()){
        for(int i=0;i<arr.size()-1;i+=2){
            if(arr[i] != 1 && arr[i+1] != 1)
                sum += (arr[i] * arr[i+1]);
            else sum += (arr[i] + arr[i+1]);
        }
        if(arr.size()%2 != 0)
            sum += arr[arr.size()-1];
    }
    
    if(!brr.empty()){
        for(int i=0;i<brr.size()-1;i+=2){
            sum += (brr[i] * brr[i+1]);
        }
        if(brr.size()%2 != 0)
            sum += brr[brr.size()-1];
    }
    
    cout<<sum<<"\n";
    return 0;
}