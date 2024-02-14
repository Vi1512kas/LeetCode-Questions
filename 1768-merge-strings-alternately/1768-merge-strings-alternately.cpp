class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int l1 = word1.length();
        int l2 = word2.length();
        int i=0,j=0;
        while(i<l1 and j<l2){
            ans+=word1[i];
            ans+=word2[j];
            i++,j++;
        }
        while(i<l1){
                ans+=word1[i];
                i++;
            }
        while(j<l2){
                ans+=word2[j];
                j++;
            }
        return ans;
    }
};