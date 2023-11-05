class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                long long target_2 = (long long)target-(long long)nums[i]-(long long)nums[j];
                int front = j+1;
                int rear = n-1;
               while(front<rear){ 
                    if(nums[front]+nums[rear]<target_2) front++;
                    else if(nums[front]+nums[rear]>target_2) rear--;
                    else{
                        vector<int> vs(4,0);
                        vs[0]=nums[i];
                        vs[1]=nums[j];
                        vs[2]=nums[front];
                        vs[3]=nums[rear];
                        ans.push_back(vs);
                        while(front<rear&&nums[front]==vs[2]) ++front;
                        while(front<rear&&nums[rear]==vs[3]) --rear;
                    }   
              }
            while(j+1<n&&nums[j+1]==nums[j]) ++j;
            }
            while(i+1<n&&nums[i+1]==nums[i]) ++i;
            
        }
        return ans;
    }
};