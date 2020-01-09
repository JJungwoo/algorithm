/*
[BOJ] 6064. 카잉 달력
https://jaimemin.tistory.com/808
*/

#include <iostream>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int gcd(int a, int b){
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

int main()
{
    io;
    int t; cin>>t;
    while(t--){
        int m,n,x,y;
        cin>>m>>n>>x>>y;
        int chk = lcm(m,n);
        while(1){
            if(x > chk || (x-1)%n+1 == y)
                break;
            x += m;
        }
        if(x > chk) cout<<"-1\n";
        else cout<<x<<"\n";
    }

    return 0;
}

/*
#include <iostream>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int gcd(int a, int b){
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int main()
{
    io;
    int t; cin>>t;
    while(t--){
        int m,n,x,y;
        cin>>m>>n>>x>>y;
        int chk = lcm(m,n);
        int k = 0, i = 0, j = 0;
        cout<<chk<<"\n";
        while(1){
            if(x == i && y == j) {
                cout<<k<<"\n";
                break;
            }
            i = (i + 1) % m, j = (j + 1) % n;
            k++;
            if(chk < k){
                cout<<k<<" ";
                cout<<"-1\n";
                break;
            }
        }
    }

    return 0;
}
*/
