/*
[boj] 11780. 플로이드 2
*/

#include <iostream>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int INF = 10000000;
int n, m;
int city[101][101], dist[101][101];
int main()
{
	io;
	cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            city[i][j] = INF + 1;
            dist[i][j] = j;
        }
        city[i][i] = 0;
    }

    for(int i=0;i<m;i++){
        int a, b, c;
        cin>>a>>b>>c;
        a--, b--;
        if(city[a][b] > c) {
            city[a][b] = c;
        }
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(city[i][j] > city[i][k] + city[k][j]){
                    dist[i][j] = dist[i][k];
                    city[i][j] = city[i][k] + city[k][j];
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(city[i][j] >= INF) cout<<"0 ";
            cout<<city[i][j]<<" ";
        }
        cout<<"\n";
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(city[i][j] >= INF || city[i][j] == 0) 
                cout<<"0\n";
            else {
                int tmp = i;
                vector<int> list;
                list.push_back(i);
                while(dist[tmp][j] != j){
                    tmp = dist[tmp][j];
                    list.push_back(tmp);
                }
                list.push_back(j);
                cout<<list.size()<<" ";
                for(auto it : list)
                    cout<<it+1<<" ";
                cout<<"\n";
            }
        }
    }

	return 0;
}

