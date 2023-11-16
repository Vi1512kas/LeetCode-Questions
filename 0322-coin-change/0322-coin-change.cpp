class Solution {
public:
    vector<int> dp;
    int ftb(int n,vector<int>& coins) {
    if (n == 0) return 0;

    if (dp[n] != -2) return dp[n];
    int res = INT_MAX;
    for (int i = 0; i < coins.size(); i++) {
        if (n - coins[i] < 0) continue; // if n is 11 and coin is of 20 then return.
        res = min(res, ftb(n - coins[i],coins));
    }
    if (res == INT_MAX) return dp[n] = INT_MAX;
    return dp[n] = 1 + res;
   }
    int coinChange(vector<int>& coins, int n) {
        dp.clear();
        dp.resize(1000005,-2);
        int a = ftb(n,coins);
        if(a==INT_MAX) return -1;
        else return a;
    }
};