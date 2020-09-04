/*
[boj] 10866. 덱
https://www.acmicpc.net/problem/10866
*/

#include <iostream>
#include <string>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

void push_front(int X) {
    node tmp = {X, NULL, NULL};
    
}

node *head;
node *tail;

int main() 
{
    io;
    int N;
    cin >> N;
    for(int i=0; i<N; i++) {
        string input;
        int value;
        cin >> input >> value;
        if(!input.compare("push_back")) {
            
        }
    }
    return 0;
}

