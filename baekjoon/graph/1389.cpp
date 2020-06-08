/*
[boj] 1389. 케빈 베이컨의 6단계
*/

#include <iostream>
#include <vector>
#include <cmath>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int INF = 987654321;
int n, m;
int net[101][101], con[101];
int main()
{
	io;
	cin>>n>>m;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            net[i][j] = INF;

    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        a--, b--;
        net[a][b] = 1;
        net[b][a] = 1;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if(i == j) net[i][j] = 0;
                else net[i][j] = min(net[i][j], net[i][k] + net[k][j]);
            }
        }
    }

    int min_path, min_value = INF;
    for(int i=0;i<n;i++){
        int tmp = 0;
        for (int j=0;j<n;j++){
            //cout<<net[i][j]<<" ";
            if(i == j) continue;
            tmp += net[i][j];
        }
        if(min_value > tmp){
            //cout<<i<<","<<j<<"="<<min_value<<":"<<net[i][j]<<"\n";
            min_value = tmp;
            min_path = i;
        }
        //cout<<"\n";
    }
    cout<<min_path+1<<"\n";

	return 0;
}

