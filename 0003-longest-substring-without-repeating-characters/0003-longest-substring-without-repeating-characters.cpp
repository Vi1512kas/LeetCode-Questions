class Solution {
public:
    int lengthOfLongestSubstring(string str) {
         int max_count = 0;
     vector<bool> count(256,false);
        int f=0;
        int s=0;
        while(s<str.size()){
            while(count[str[s]]){
                count[str[f]] = false;
                f++;
            }
            count[str[s]] = true;
            max_count = max(max_count,s-f+1);
            s++;
        }
     return max_count;
    }
  
  
};