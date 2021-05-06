/*
[boj] 2531. 회전 초밥
https://www.acmicpc.net/problem/2531
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, d, k, c, answer;
vector<int> v, pcnt;
unordered_map<int, int> m;
int main() 
{
    io;
    cin >> N >> d >> k >> c;
    v.resize(N*2);
    pcnt.resize(N*2);
    for(int i=0;i<N;i++) {
        cin >> v[i];
    }
    
    for(int i=0;i<k - 1;i++) {
        v[i+N] = v[i];
    }
    
    m[c]++;
    for(int i=0;i<k - 1;i++) {
        m[v[i]]++;
    }
    
    answer = m.size();
    
    for(int i=0;i<N;i++) {
        m[v[i + k - 1]]++;
        int size = m.size();
        answer = max(answer, size);
        if (m.find(v[i]) != m.end()) {
            m[v[i]]--;
            if (m[v[i]] == 0)
                m.erase(v[i]);
        }        
    }
    cout<<answer<<"\n";
    return 0;
}
