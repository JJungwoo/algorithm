/*
[boj] 1662. 압축
https://www.acmicpc.net/problem/1662
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    io;
    string S, ans = "", buf = "";
    cin >> S;
    stack<string> stc, sti;
    bool chk = false;
    for(int i=S.length()-1;i>=0;i--) {
        if(S[i] == ')') {
            if (!sti.empty()) {
                ans += sti.top();
                sti.pop();
            }
            stc.push(")");
        }
        else if(S[i] == '(') {
            string tmp = "";
            if(stc.empty()) goto end;
            if (!sti.empty()) {
                tmp = sti.top();
                sti.pop();
                sti.push(tmp);
            }
            if (stc.top() == ")") 
                stc.pop();
            chk = true;
        } else {
            if (chk) {
                int loop = (int)(S[i] - '0');
                if (!sti.empty()) {
                    string tmp = sti.top(); sti.pop();
                    while(loop--) {
                        buf += tmp;
                    }
                    sti.push(buf);
                    buf = "";
                }
                chk = false;
            } else {
                if (!sti.empty()) {
                    string tmp = "";
                    tmp += S[i];
                    tmp += sti.top();
                    sti.pop();
                    sti.push(tmp);
                }
                else
                    sti.push(to_string(S[i]-'0'));
            }
        }   

    }

    if(!sti.empty()) {
        ans += sti.top();
        cout<<ans.length()<<"\n";
    }else{
end: 
    cout<<"0\n";
    }
    
    
    return 0;
}