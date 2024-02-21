class Solution {
public:
    // int f(int sr,int sc,int er,int ec){
    //     if(sr==er and sc==ec) return 1;
    //     if(sr>er||sc>ec) return 0;
    //     int right = f(sr,sc+1,er,ec);
    //     int down = f(sr+1,sc,er,ec);
    //     return down+right;
    // }
    int ftb(vector<vector<int>> &dp,int sr,int sc,int er,int ec){
        if(sr==er and sc==ec) return 1;
        if(sr>er||sc>ec) return 0;
        if(dp[sr][sc]!=-1) return dp[sr][sc];
        int right = ftb(dp,sr,sc+1,er,ec);
        int down = ftb(dp,sr+1,sc,er,ec);
        return dp[sr][sc] = down+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return ftb(dp,0,0,m-1,n-1);
    }
};