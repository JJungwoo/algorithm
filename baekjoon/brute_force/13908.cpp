/*
[boj] 13908. 비밀번호
https://www.acmicpc.net/problem/13908
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, m, ans;
vector<int> select_num, secret_num;
void find_numbers_list(int idx) {
    if(secret_num.size() == n) {
        int cnt = 0;
        for(int i : select_num) {
            bool chk = false;
            for(int j : secret_num) {
                if(i == j) {
                    chk = true;
                    break;
                }
            }
            if (chk) {
                cnt++;
            }
        }
        if(m == cnt)
            ans++;
        return;
    }

    for(int i=0;i<10;i++) {
        secret_num.push_back(i);
        find_numbers_list(idx+1);
        secret_num.pop_back();
    }
}
int main()
{
    io;
    cin >> n >> m;
    select_num.resize(m);
    for(int i=0;i<m;i++) {
        cin >> select_num[i];
    }
    find_numbers_list(0);
    cout<<ans<<"\n";
    return 0;
}

