class Solution {
public:
    int dp[1005][105][2];
    int ftb(vector<int> &v,int i,int k,bool on){
    if(i==v.size()) return 0;
    if(dp[i][k][on]!=-1) return dp[i][k][on];
    int ans  = INT_MIN;
    ans = ftb(v,i+1,k,on); // avoid wala case.
    if(on){
        // true means kharid liya ab bechna h no more.
        ans = max(ans,v[i] + ftb(v,i+1,k-1,false)); // bechna
    } else{
        if(k>0) ans = max(ans,ftb(v,i+1,k,true)-v[i]);
    }
    dp[i][k][on]=ans;   
    return ans;
}
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return ftb(prices,0,k,false);
    }
};