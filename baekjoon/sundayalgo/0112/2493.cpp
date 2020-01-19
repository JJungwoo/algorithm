/*
[BOJ] 2493. 탑
*/
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
int atop[500001];
stack<int> st;
vector<int> ans;
int main()
{
    io;
    cin>>n;
    for(int i=1;i<=n;i++) {
        bool find = false;
        cin>>atop[i];
        while(!st.empty()){
            if(atop[st.top()] > atop[i]) {
                find = true;
                cout<<st.top()<<" ";
                break;
            }
            st.pop();
        }
        if(!find) cout<<"0 ";
        st.push(i);
    }
    cout<<"\n";
    return 0;
}