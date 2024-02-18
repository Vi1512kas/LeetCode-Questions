// #define pp pair<int,string>
class Solution {
public:
    struct compare{
    bool operator()(pair<int,string>&a,pair<int,string>&b){
                        if(a.first==b.first)
                        return a.second>b.second;//sort aced
                        return a.first<b.first;//sort dec
    }
};
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
          unordered_map<string,int>mp;
          
        // string ans="";
        vector<string>ans;
        for(auto i:words)
        {
            mp[i]++;
        }
   priority_queue<pair<int,string>,vector<pair<int,string>>,compare> pq;
        for(auto i:mp)
        {
          pq.push({i.second,i.first});  
    
        }
        while(k--)
        {
          pair<int,string>x=pq.top();
              
              ans.push_back(x.second);
           pq.pop();
        
        }
        return ans;
    }
};