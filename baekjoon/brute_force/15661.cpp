/*
[boj] 15661. 링크와 스타트
https://www.acmicpc.net/problem/15661
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, ans = 987654321;
int arr[21][21];
int main()
{
    cin >> N;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
        }
    }

    for(int k=2;k<=N/2;k++) {
        vector<int> team;
        for(int i=0;i<k;i++) team.push_back(0);
        for(int i=0;i<N - k;i++) team.push_back(1);
            
        do{
            vector<int> tv1, tv2;
            int t1 = 0, t2 = 0;
            for(int i=0;i<N;i++) {
                if(team[i] == 0) tv1.push_back(i);
                else tv2.push_back(i);
            }
            for(int i=0;i<tv1.size()-1;i++) {
                for(int j=i+1;j<tv1.size();j++) {
                    t1 += arr[tv1[i]][tv1[j]] + arr[tv1[j]][tv1[i]];
                }
            }
            for(int i=0;i<tv2.size()-1;i++) {
                for(int j=i+1;j<tv2.size();j++) {
                    t2 += arr[tv2[i]][tv2[j]] + arr[tv2[j]][tv2[i]];
                }
            }
            ans = min(ans, abs(t1-t2));
        }while(next_permutation(team.begin(), team.end()));
    }

    cout<<ans<<"\n";
    return 0;
}