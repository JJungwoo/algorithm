/*
[BOJ] 1735. 분수 합
*/

#include <iostream>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int gcd(int a, int b)
{
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main()
{   
    io;
    int ua, da, ub, db;
    cin>>ua>>da>>ub>>db;

    int up = gcd(ua, da);
    int down = gcd(ub, db);

    

    return 0;
}