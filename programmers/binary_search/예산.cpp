#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool find(int value, int cnt, int remain){
    return ((value * cnt) < remain);
}

int find_stand(int max, int stand, int cnt, int remain){
    int start = stand, end = max;
    while(start < end){
        int mid = (start + end) / 2;
        cout<<"find_stand: "<<start<<", "<<end<<" : "<<mid<<"\n";
        if(find(mid, cnt, remain) == true){
            start = mid + 1;
        }else {
            end = mid - 1;
        }
    }
    return end;
}

int solution(vector<int> budgets, int M) {
    int answer = 0;
    int size = budgets.size();
    sort(budgets.begin(), budgets.end());
    int stand = M/size;
    for(auto it : budgets){
        cout<<it<<"\n";
        if(it < stand){
            size--;
            M -= it;
        }
        else {
            answer = find_stand(it, stand, size, M);
            break;
        }
    }
    return answer;
}
