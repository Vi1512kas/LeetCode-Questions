#include<unordered_map>
#define pp pair<int,char>
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        priority_queue<pp> pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(!pq.empty()){
            pp vs = pq.top();
            pq.pop();
            for(int i=0;i<vs.first;i++){
                ans+=vs.second;
            }
        }
        return ans;
        
    }
};