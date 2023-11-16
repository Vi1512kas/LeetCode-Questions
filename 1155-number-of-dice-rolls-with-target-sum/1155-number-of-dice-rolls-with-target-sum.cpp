#define ll long long int
#define mod 1000000007
class Solution {
public:
    vector<vector<ll> > dp;
    int ftb(int n,int d,int t){
         if(n==0 && t==0) return 1;
         if(n==0) return 0;
         if(dp[n][t]!=-1) return dp[n][t];
         ll count=0;
         for(int i=1;i<=d;i++){
            if(t-i<0)  break;
            count = ((count % mod) + (ftb(n-1,d,t-i) % mod)) % mod;
         }
         return dp[n][t] = count;
    }
    int numRollsToTarget(int n, int k, int target) {
       dp.clear();
       dp.resize(31,vector<ll>(1005,-1));
       return ftb(n,k,target);
    }
};