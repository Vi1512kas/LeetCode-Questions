#define pp pair<int,int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        priority_queue<pp> pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        vector<int> ans;
        while(!pq.empty() and k-->0){
            pp vs = pq.top();
            pq.pop();
            ans.push_back(vs.second);
        }
        return ans;
    }
};