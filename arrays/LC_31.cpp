class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int curr=-1;

        for(int i=n-1;i>0;i--){
            if(nums[i-1]<nums[i]){
                curr=i-1;
                break;
            }
        }
        if(curr==-1){
            reverse(nums.begin(),nums.end());
            return ;
        }

        for(int i=n-1;i>curr;i--){
            if(nums[i]>nums[curr]){
                int k=i;
                swap(nums[i],nums[curr]);
                break;
            }
        }

      
        reverse(nums.begin()+curr+1,nums.end());

    }
};