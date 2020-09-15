/*
[swea] 9940. 순열1
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AXHx23oq0REDFAXR&categoryId=AXHx23oq0REDFAXR&categoryType=CODE
*/

#include <iostream>
#include <unordered_set>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main() 
{
    io;
    int test_case;
	int T;
    cin >> T;
    for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        cin >> N;
        unordered_set<int> s;
        bool check = true;
        for(int i=0;i<N;i++) {
            int input;
            cin >> input;
            if(input > N || s.count(input) != 0) check = false;
            else s.insert(input);
        }
        if(check)
            cout<<"#"<<test_case<<" Yes\n";
        else 
            cout<<"#"<<test_case<<" No\n";
    }
    return 0;
}

