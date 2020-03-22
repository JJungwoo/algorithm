#include <iostream>
#include <cstring>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    io;
    int tcase;
    cin>>tcase;
    for(int t = 0; t < tcase ;t++)
    {
        string in;
        cin>>in;
        int k, ans = 0;
        cin>>k;
        int size = in.size();
        for(int i=0;i<size-k;i++){
            if(in[i] == '-'){
                ans++;
                for(int z=0;z<size;z++){
                    cout<<in[z]<<" ";
                }
                cout<<"\n";
                cout<<i<<"\n";
                for(int j=i;j<k;j++){
                    if(in[j] == '-') in[j] = '+';
                    else if(in[j] == '+') in[j] = '-';
                }
            }
            
        }
        bool check = true;
        for(int i=0;i<size;i++){
            if(in[i] == '-'){
                check = false;
            }
        }
        cout<<"Case #"<<t+1<<": ";
        if(check) cout<<ans<<"\n";
        else cout<<"IMPOSSIBLE\n";
    }
    
    return 0;
}