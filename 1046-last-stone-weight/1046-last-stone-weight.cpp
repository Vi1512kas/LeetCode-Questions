class Solution {
public:
    int lastStoneWeight(vector<int>& v) {
        priority_queue<int> pq(begin(v), end(v));
        while(pq.size()>1){
            int p=pq.top();
            pq.pop();
            int q=pq.top();
            pq.pop();
            int d = abs(p-q);
            if(d!=0) pq.push(d);
        }
        if (pq.size()==0) return 0;
        else return pq.top();
    }
};