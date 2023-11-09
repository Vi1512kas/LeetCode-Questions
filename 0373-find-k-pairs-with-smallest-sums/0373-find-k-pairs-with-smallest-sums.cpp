#define pp pair<int,pair<int,int>>
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        for(int i=0;i<nums1.size();i++){
            pq.push({nums1[i]+nums2[0],{i,0}});
        }
        pp vs;
        while(k-- && !pq.empty()){
            vs=pq.top();
            pq.pop();
            int ele = vs.first;
            int fi = vs.second.first;
            int si = vs.second.second;
            ans.push_back({nums1[fi],nums2[si]});
            if(si+1<nums2.size()){
                pq.push({nums1[fi]+nums2[si+1],{fi,si+1}});
            }
        }
        return ans;
    }
};