#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int psize = phone_book.size();
    map<string, int> m;
    //cout<<psize<<"\n";
    for(int i=0;i<psize;i++){
        cout<<phone_book[i]<<"\n";
        int ssize = phone_book[i].size();
        m.insert(make_pair(phone_book[i], ssize));
        string tmp = "";
        cout<<"ssize:"<<ssize<<"\n";
        for(int j=0;j<ssize;j++){
            tmp += phone_book[i][j];
            cout<<"tmp:"<<tmp<<":"<<phone_book[i][j]<<"\n";
            auto iter = m.find(tmp);
            if(iter != m.end() && iter->second != ssize){
                cout<<"tmp:"<<tmp<<","<< ssize<<"\n";
                answer = false;
            }
        }
    }
    return answer;
}

int main()
{
    vector<string> tmp;
    tmp.push_back("119");
    tmp.push_back("97674223");
    tmp.push_back("1195524421");
    cout<<solution(tmp)<<"\n";
    return 0;
}