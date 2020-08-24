/*
[LeetCode] 939. Minimum Area Rectangle
https://leetcode.com/problems/minimum-area-rectangle/
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

class Solution {
public:
    int minAreaRect(vector<vector<int> >& points) {
        set<pair<int, int> > s;
        for(auto p:points){
            s.insert({p[0],p[1]});
        }
        for(auto p:s){
            cout<<p.first<<","<<p.second<<"\n";
        }
        int area=INT_MAX;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                if(points[i][0]!=points[j][0] && points[i][1]!=points[j][1]){
                    pair<int,int> op1={points[i][0],points[j][1]};
                    pair<int,int> op2={points[j][0],points[i][1]};
                    if(s.count(op1) && s.count(op2)){
                        int l=abs(points[i][0]-points[j][0]),w=abs(points[i][1]-points[j][1]);
                        area=min(area,l*w);
                    }
                }
            }
        }
        return area==INT_MAX ? 0 : area;
    }
};

int main()
{
    io;
    return 0;
}