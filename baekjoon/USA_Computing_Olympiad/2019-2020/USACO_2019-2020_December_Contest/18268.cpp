
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

string map[21][21];
int map[21][21];
int main()
{
    int answer = 0;
    int k, n;
    cin>>k>>n;
    for(int i=0;i<k;i++){
        vector<int> v;
        v.resize(n+1);
        for(int j=0;j<n;j++){
            cin>>v[j];
        }
        for(int x=0;x<v.size()-1;x++){
            for(int y=x+1;y<v.size();y++){
                if(v[x] != 0 && v[y] != 0)
                    map[v[x]][v[y]] += 1;
                if(map[v[x]][v[y]] == k) {
                    cout<<v[x]<<" "<<v[y]<<"\n";
                    answer++;
                }
            }
        }
    }

    cout<<answer<<"\n";
    return 0;
}