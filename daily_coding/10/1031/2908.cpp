/*
[boj] 2908. 상수 
https://www.acmicpc.net/problem/2908
*/

#include <iostream>
#include <algorithm>
#include <string>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main()
{
    io;
    string A, B;
    cin >> A >> B;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    cout<<max(stoi(A), stoi(B))<<"\n";
    return 0;
}

/*
// 라이브러리 구현
#include <iostream>
#include <algorithm>
#include <string>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
string reverse_func(string input) {
    string ret = "";
    for(int i=input.size()-1;i>=0;i--) {
        ret += input[i];
    }
    return ret;
}
int stoi_func(string input) {
    int ret = 0, tmp = 1;
    for(int i=input.size()-1;i>=0;i--) {
        ret += (int)((input[i] - '0') * tmp);
        tmp *= 10;
    }
    return ret;
}
int main()
{
    io;
    string A, B;
    cin >> A >> B;
    cout<<max(stoi_func(reverse_func(A)), stoi_func(reverse_func(B)))<<"\n";
    return 0;
}
*/