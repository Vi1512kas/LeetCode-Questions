class Solution {
public:
    vector<int> dp;
    int ftb(int i,vector<int> array){
      if(i==array.size()-1) return array[i];
      if(i==array.size()-2) return max(array[i],array[i+1]);
      if(dp[i]!=-1) return dp[i];
      return dp[i] = max(ftb(i+1,array),array[i]+ftb(i+2,array));
    }
    int rob(vector<int>& nums) {
        dp.resize(nums.size()+1,-1);
        return ftb(0,nums);
    }
};