class Solution {
public:
    long long int solve(vector<int> &nums){
    int n=nums.size();
    
    vector<int> dp(n,-1);
    dp[0] = nums[0];
    for(int i=1;i<n;i++){
            int lena = nums[i];
            if(i>1) lena+=dp[i-2];
            int notlena = dp[i-1];
            dp[i] = max(lena,notlena);
    }
    return dp[n-1];
}
    int rob(vector<int>& nums) {
        int n=nums.size();
       if(n==1) return nums[0];
       vector<int> vs1,vs2;
      for(int i=0;i<n;i++){
        if(i!=0) vs1.push_back(nums[i]);
        if(i!=n-1) vs2.push_back(nums[i]);
    }
    long long int a = solve(vs1);
    long long int b = solve(vs2);
    return max(a,b);
    }
};