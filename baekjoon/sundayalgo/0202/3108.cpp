/*
[BOJ] 3108. logo
*/

#include <iostream>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int def = 500;
int n, ans;
int checkmap[1001][1001];
int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        int x1, y1, x2, y2;
        bool check = false;
        cin>>x1>>y1>>x2>>y2;
        x1 += def, y1 += def, x2 += def, y2 += def;
        for(int j=0;j<=abs(x2-x1);j++){
            if(checkmap[x1 + j][y1] || checkmap[x1][y1 + j] ||
                checkmap[x2 - j][y2] || checkmap[x2][y2 - j])
            {
                //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
                //cout<<checkmap[x1 + j][y1]<<", "<<checkmap[x1][y1 + j]<<", "
                //<<checkmap[x2 - j][y2]<<", "<<checkmap[x2][y2 - j]<<"\n";
                check = true;
            }
            checkmap[x1 + j][y1] = 1;
            checkmap[x1][y1 + j] = 1;
            checkmap[x2 - j][y2] = 1;
            checkmap[x2][y2 - j] = 1;
            //cout<<x1 + j<<","<<y1<<", "<<x1<<","<<y1 + j<<", "
            //<<x2 - j<<","<<y2<<", "<<x2<<","<<y2 - j<<"\n";
        }
        if(!check) ans++;
    }
    cout<<ans<<"\n";

    return 0;
}