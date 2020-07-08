/*
[boj] 8980. 택배
https://www.acmicpc.net/problem/8980
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, c, m, ans;
struct obj{
    int a, b, c;    // 보내는 마을, 받는 마을, 박스 개수
};
vector<obj> v;
bool cmp(obj a, obj b){
    if(a.b == b.b)
        return a.a < b.a;
    else 
        return a.b < b.b;
}
int city[2001];
int main()
{
    io;
    cin>>n>>c;  // 마을수, 트럭 용량
    cin>>m;     // 박스정보
    v.resize(m+1);
    for(int i=0;i<m;i++)
        cin>>v[i].a>>v[i].b>>v[i].c;

    sort(v.begin(), v.end(), cmp);

    for(auto it : v){
        int cnt = 0;
        for(int j=it.a;j<it.b;j++)
            cnt = max(cnt, city[j]);

        int value = min(it.c, c - cnt);
        ans += value;

        for(int j=it.a;j<it.b;j++)
            city[j] += value;
    }
    cout<<ans<<"\n";
    return 0;
}