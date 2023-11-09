class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double ts,rs;
        for(int i=0;i<nums.size();i++){
            ts+=nums[i];
            pq.push(nums[i]*1.0); // convert to double.
        }
        rs=ts/2;
        int count=0;
        while(ts>rs){
            double temp=pq.top();
            pq.pop();
            ts-=(temp/2);
            pq.push(temp/2);
            count++;
        }
        return count;
    }
};