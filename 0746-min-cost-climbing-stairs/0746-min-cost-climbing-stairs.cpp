class Solution {
public:
    vector<int> dp;
    int f(vector<int> cost,int i){
        if(i==0 or i==1) return cost[i];
        if(dp[i]!=-1) return dp[i];
        return dp[i] = cost[i]+min(f(cost,i-1),f(cost,i-2));
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        dp.resize(n,-1);
        return min(f(cost,n-1),f(cost,n-2));
        
    }
};