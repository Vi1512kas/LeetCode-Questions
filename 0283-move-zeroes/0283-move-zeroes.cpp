class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,k=0,count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count++;
            }
            else{
                nums[k++]=nums[i];
            }
        }
        while(k<n){
            if(count!=0){
                nums[k]=0;
                count--;
            }
            else{
                break;
            }
            k++;
        }
    }
};