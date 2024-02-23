class Solution {
public:
    
    
    int longestCommonSubsequence(string a, string b) {
        short m[1005][1005]= {};
        for(int i=0;i<a.length();i++){
            for(int j=0;j<b.length();j++){
                // dp[i+1][j+1] = (text1[i] == text2[j])? 1+ dp[i][j]:max(dp[i][j+1],dp[i+1][j]);   
                m[i + 1][j + 1] = a[i] == b[j] ? m[i][j] + 1 : max(m[i + 1][j], m[i][j + 1]);
            }
        }
        return m[a.length()][b.length()];
    }
};