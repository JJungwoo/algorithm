/*
[boj] 1507. 궁금한 민호
https://www.acmicpc.net/problem/1507
*/

#include <iostream>
#include <cstring>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int INF = 1e9;
int n;
int city[20][20];
bool dist[20][20];
int floyd(){
    int ans = 0;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == j || j == k || k == i) continue;
                else if(city[i][j] > city[i][k] + city[k][j])
                    return -1;
                else if(city[i][j] == city[i][k] + city[k][j])
                    dist[i][j] = false;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j] == false) continue;
            else ans += city[i][j];
        }
    }
    return ans/2;
}
int main()
{
	io;
    cin>>n;
    memset(dist, true, sizeof(dist));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>city[i][j];
    
    cout<<floyd()<<"\n";

	return 0;
}
