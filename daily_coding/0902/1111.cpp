/*
[boj] 1111. IQ Test 
https://www.acmicpc.net/problem/1111
ref : https://coloredrabbit.tistory.com/12
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int numbers[51];
int main() 
{
    io;
    int N;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> numbers[i];
    }
    if(N == 1) 
        cout << "A\n";
    else if(N == 2) {
        if(numbers[0] == numbers[1]) 
            cout << numbers[0] << "\n";
        else 
            cout << "A\n";
    }
    else {
        int a = 0;
        int x = (numbers[1] - numbers[0]);
        int y = (numbers[2] - numbers[1]);
        if(x != 0)
            a = y / x;
        int b = numbers[1] - numbers[0] * a;
        bool ch = true;
        for(int i=1;i<N;i++){
            if(numbers[i] != numbers[i-1] * a + b) {
                ch = false;
                break;
            }
        }
        if(ch) 
            cout << numbers[N-1] * a + b << "\n";
        else 
            cout<<"B\n";
    }
    return 0;
}