/*
[boj] 16943. 숫자 재배치
https://www.acmicpc.net/problem/16943
*/

// dfs brute force

#include <iostream>
#include <cstring>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;
string a, b;
bool visited[11];
vector<char> tmp;
ll lb, ans = -1;
void solve(int cnt) {
    if(cnt == a.size()) {
        string tstr = "";
        for(auto it : tmp)
            tstr += it;
        if(tstr[0] == '0') return;
        ll tmp = atoi(tstr.c_str());
        if(tmp <= lb) {
            ans = max(ans, tmp);
        }
        return;
    }

    for(int i=0;i<a.size();i++) {
        if(visited[i]) continue;
        visited[i] = true;
        tmp.push_back(a[i]);
        solve(cnt+1);
        tmp.pop_back();
        visited[i] = false;
    }
}
int main() 
{
    io;
    cin>>a>>b;
    lb = atoi(b.c_str());
    bool check = false;
    for(auto it : b){
        if(a[a.find(it)] == it){
            check = true;
            break;
        }
    }
    if(!check) {
        cout<<"-1\n";
        return 0;
    }
    else 
        solve(0);
    cout<<ans<<"\n";
    return 0;
}


/*
// next_permutation

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int ans = -1, b;
string a;
int main() 
{
    io;
    cin>>a>>b;
    vector<int> tmp(a.size(), 0);

    for(int i=0;i<tmp.size();i++)
        tmp[i] = i;

    do {
        string stmp = "";
        for(auto idx : tmp)
            stmp += a[idx];
        
        if(stmp[0] == '0') continue;
        int result = stoi(stmp);
        if(result <= b && result > ans) {
            ans = result;
        }
    } while (next_permutation(tmp.begin(), tmp.end()));

    cout<<ans<<"\n";
    return 0;
}
*/