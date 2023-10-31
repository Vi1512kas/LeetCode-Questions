class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> vs;
        unordered_map<string,vector<string> > mp;
        for(auto it:strs){
            string org=it;
            sort(org.begin(),org.end());
            if(mp.find(org)==mp.end()){
                vs.push_back(it);
                mp[org]=vs;
                vs.pop_back();
            }
            else{
                mp[org].push_back(it);
            }
        }
        for(auto x:mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};