/*
[BOJ] 11576. base conversion
*/
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int a, b, m, value = 0;
    scanf("%d %d %d", &a, &b, &m);
    for(int i=m-1;i>=0;i--){
        int tmp;scanf("%d",&tmp);
        value += (pow(a, i) * tmp);
    }
    vector<int> ans;
    while(value>b){
        ans.push_back(value % b);
        value /= b;
    }

    if(value%b == 0){
        ans.push_back(0);
        ans.push_back(value/b);
    } else ans.push_back(value);
    reverse(ans.begin(), ans.end());
    int len = ans.size();
    for(int i=0;i<len;i++){
        printf("%d ", ans[i]);
    }
    return 0;
}
