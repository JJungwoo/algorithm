/*
[boj] 11728. 배열 합치기
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n,m;
vector<int> a, b, ans;
int main()
{
    io;
    cin>>n;
    cin>>m;
    a.resize(n,0);
    b.resize(m,0);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    int aidx = 0, bidx = 0;
    while(aidx != n || bidx != m){
        if(aidx == n) {
            ans.push_back(b[bidx]);
            bidx++; 
        }
        else if(bidx == m) {
            ans.push_back(a[aidx]);
            aidx++;
        }
        else if(a[aidx] < b[bidx]) {
            ans.push_back(a[aidx]);
            aidx++;
        }
        else {
            ans.push_back(b[bidx]);
            bidx++;
        }
    }

    for(auto it : ans)
        cout<<it<<" ";
    cout<<"\n";
    return 0;
}