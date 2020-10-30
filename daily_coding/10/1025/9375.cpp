/*
[boj] 9375. 패션왕 신해빈
https://www.acmicpc.net/problem/9375
*/

#include <iostream>
#include <unordered_map>
#include <string>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int T, N;
int main() 
{
    io;
    cin >> T;
    while(T--) {
        unordered_map<string, int> umap;
        cin >> N;
        for(int i=0;i<N;i++) {
            string A, B;
            cin >> A >> B;
            umap[B]++;
        }
        int sum = 1;
        for(auto it : umap) {
            sum *= (it.second + 1);
        }
        cout<<sum - 1<<"\n";
    }
    return 0;
}