#include <iostream>
#include <cmath>
#define pp pair<int,pair<int,int>>
class Solution {
public:
    priority_queue<pp,vector<pp>,greater<pp>> pq;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)    {
        vector<vector<int>> ans;
        vector<int> v;
      for(int i=0;i<points.size();i++){
          int d = (points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
          pq.push({d,{points[i][0],points[i][1]}});
      }
        int i=0;
        while(k-- > 0){
            v.push_back(pq.top().second.first);
            v.push_back(pq.top().second.second);
            ans.push_back(v);
            pq.pop();
            v.clear();
        }
        return ans;
    }
};


