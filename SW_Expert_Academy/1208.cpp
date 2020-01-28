/*
[SW_EA] 14889. [S/W 문제해결 기본] 1일차 - Flatten
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int dump, ans;

void find_dump(vector<int> &box){
    for(int i=0;i<dump;i++){
        (*max_element(box.begin(), box.end()))--;
        (*min_element(box.begin(), box.end()))++;
    }
    ans = (*max_element(box.begin(), box.end())) 
        - (*min_element(box.begin(), box.end()));
}

int main()
{
    io;
    int T = 10, test_case;

    for(test_case = 1; test_case <= T; test_case++){
        
        vector<int> box;
        ans = 0;
        cin>>dump;
        for(int i=1;i<=100;i++){
            int tmp; cin>>tmp;
            box.push_back(tmp);
        }
        find_dump(box);
        cout<<"#"<<test_case<<" "<<ans<<"\n";
    }

    return 0;
}