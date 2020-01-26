/*
[BOJ] 6603. lotto
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int k;
int s[14];
bool visited[14];
int output[7];

void dfs(int x, int count){
    if(count == 6){
        for(int i=0;i<count;i++){
            cout<<output[i]<<" ";
        }
        cout<<"\n";
        return ;
    }
    
    for(int i=x;i<k;i++){
        if(!visited[i]){
            visited[i] = true;
            output[count] = s[i];
            dfs(i, count+1);
            visited[i] = false;
        }
    }    
}
/*
int main()
{
    io;
    while(1){
        cin>>k;
        if(k == 0){
            return 0;
        }
        for(int i=0;i<k;i++){
            cin>>s[i];
        }
        dfs(0, 0);
        cout<<"\n";
        memset(visited, 0, sizeof(visited));
    }

    return 0;
}
*/
/// next_permutation

int main()
{
    io;
    while(1){
        cin>>k;
        if(k == 0){
            return 0;
        }
        for(int i=0;i<k;i++){
            cin>>s[i];
        }
        memset(visited, 0, sizeof(visited));
        for(int i=0;i<6;i++) visited[i] = true;
        do{
            for(int i=0;i<k;i++){
                if(visited[i])
                    cout<<s[i]<<" ";
            }
            cout<<"\n";
        }while(prev_permutation(visited, visited + k));
        cout<<"\n";
    }

    return 0;
}