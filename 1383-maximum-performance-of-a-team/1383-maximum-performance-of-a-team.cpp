#define pp pair<long long int,long long int> 
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pp> v;
        for(int i=0;i<n;i++){
            v.push_back({efficiency[i],speed[i]});
        }
        sort(v.rbegin(),v.rend());
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        long long int ts=0;
        long long int ans=0;
        for(int i=0;i<n;i++){
            if(pq.size()==k){
                ts-=pq.top().first;
                pq.pop();
            }
            pq.push({v[i].second,v[i].first});
            ts+=v[i].second;
            ans = max(ans,ts*v[i].first);
        }
        return (ans%int(1000000007));
        
        
    }
};