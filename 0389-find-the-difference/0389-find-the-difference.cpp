class Solution {
public:
    char findTheDifference(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<int> first(26,0);
        vector<int> second(26,0);
        for(int i=0;i<n;i++){
            first[s[i]-'a']++;
        }
        for(int i=0;i<m;i++){
            second[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(first[i]!=second[i]){
                return (i+97);
            }
        }
        return -1;
    }
};