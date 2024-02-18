class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum=0;
        for(auto it:nums){
            sum+=it;
        }
        double s = sum/2.0;
        int ans=0;
        priority_queue<double> pq(nums.begin(),nums.end());
        while(sum>s){
        double ele = pq.top();
        pq.pop();
        pq.push(ele/2.0);
        sum-=(ele/2.0);ans++;
        }
        return ans;
        
    }
};