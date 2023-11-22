class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int> > pq(nums.begin(),nums.end());
        int m = INT_MIN;
        int sum=0;
        for(auto it:nums) sum+=it;
        while(k--){
            int m=pq.top();
            if(m==0) break;
            pq.pop();
            sum-=m;
            pq.push(-1*m);
            sum+=(-m);
        }
        return sum;
        
    }
};