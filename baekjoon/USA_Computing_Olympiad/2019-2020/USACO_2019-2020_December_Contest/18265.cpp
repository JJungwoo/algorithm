#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
// 3 6 9 12 15 18 21 24 27 30 
// 33 36 39 42 45 48 51 54 57 60

// 5 10 15 20 25 30
// 35 40 45 50 55 60

// 15 30
// 45 60
#define MAX_NUM 1000000000
int n;
int main()
{
    cin>>n;
    int left = 1, right = MAX_NUM;
    while(left + 1 < right){
        int mid = (left + right) / 2;
        if(mid > n + )
            left = mid + 1;
        else 
            right = mid - 1;
    }
    cout<<right<<"\n";   
    return 0;
}