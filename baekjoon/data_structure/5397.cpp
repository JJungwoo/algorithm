/*
[boj] 5397. 키로거 
https://www.acmicpc.net/problem/5397
*/

#include <iostream>
#include <string>
#include <list>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    io;
    string input;
    int T;
    cin >> T;
    while(T--) {
        list<char> answer;
        int idx = 0;
        cin >> input;
        auto cursor = answer.end();
        for(auto c : input) {
            if(c == '>') {
                if(cursor != answer.end()) 
                    cursor++;
            }
            else if(c == '<') {
                if(cursor != answer.begin()) 
                    cursor--;;
            } 
            else if(c == '-') {
                if(cursor != answer.begin()) {
                    auto tmp = cursor;
                    cursor--;
                    answer.erase(cursor);
                    cursor = tmp;
                }
            }
            else {
                answer.insert(cursor, c);
            }
        }
        for(auto c : answer)
            cout<<c;
        cout<<"\n";
    }
    return 0;
}