class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,pair<int,int>>>p;
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            double a=(double)arr[i]/arr[j];
            p.push({a,{arr[i],arr[j]}});
            if(p.size()>k)
            p.pop();
        }
    }
    vector<int>ans;
    ans.push_back(p.top().second.first);
    ans.push_back(p.top().second.second);
    return ans;
    }
};